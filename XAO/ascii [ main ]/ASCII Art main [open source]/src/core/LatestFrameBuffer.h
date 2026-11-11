#pragma once

#include <atomic>
#include <condition_variable>
#include <cstdint>
#include <mutex>
#include <optional>
#include <utility>

namespace asciicam::core {

/// A thread-safe, single-slot mailbox for a producer/consumer pipeline.
///
/// The producer (camera thread) calls @ref push as fast as frames arrive.
/// The consumer (processing thread) calls @ref wait_pop and always receives the
/// **most recent** value; any value the consumer did not take before the next
/// @ref push is dropped. This "latest wins" policy is what keeps a real-time
/// feed from accumulating latency when rendering is slower than capture — the
/// single most important decision for a smooth camera feed.
///
/// The type is intentionally generic (not tied to `cv::Mat`) so the threading
/// core stays dependency-free and unit-testable without OpenCV.
template <class T>
class LatestFrameBuffer {
public:
    LatestFrameBuffer() = default;

    LatestFrameBuffer(const LatestFrameBuffer&) = delete;
    LatestFrameBuffer& operator=(const LatestFrameBuffer&) = delete;

    /// Store a new value, replacing (and counting as dropped) any unconsumed one.
    void push(T value) {
        {
            std::lock_guard lock(mutex_);
            if (slot_.has_value()) {
                ++dropped_;
            }
            slot_ = std::move(value);
        }
        cv_.notify_one();
    }

    /// Block until a value is available or the buffer is closed.
    /// Returns std::nullopt only when the buffer is closed and empty.
    [[nodiscard]] std::optional<T> wait_pop() {
        std::unique_lock lock(mutex_);
        cv_.wait(lock, [this] { return slot_.has_value() || closed_; });
        if (slot_.has_value()) {
            std::optional<T> out = std::move(slot_);
            slot_.reset();
            return out;
        }
        return std::nullopt;  // closed and empty
    }

    /// Non-blocking take; returns std::nullopt if no value is waiting.
    [[nodiscard]] std::optional<T> try_pop() {
        std::lock_guard lock(mutex_);
        if (!slot_.has_value()) {
            return std::nullopt;
        }
        std::optional<T> out = std::move(slot_);
        slot_.reset();
        return out;
    }

    /// Wake any waiting consumer. After close(), wait_pop() drains the remaining
    /// value (if any) and then returns std::nullopt.
    void close() {
        {
            std::lock_guard lock(mutex_);
            closed_ = true;
        }
        cv_.notify_all();
    }

    [[nodiscard]] bool closed() const {
        std::lock_guard lock(mutex_);
        return closed_;
    }

    /// Number of frames overwritten before being consumed — a live health metric
    /// for the pipeline (high drop counts mean rendering can't keep up).
    [[nodiscard]] std::uint64_t dropped() const { return dropped_.load(); }

private:
    mutable std::mutex mutex_;
    std::condition_variable cv_;
    std::optional<T> slot_;
    bool closed_ = false;
    std::atomic<std::uint64_t> dropped_{0};
};

}  // namespace asciicam::core
