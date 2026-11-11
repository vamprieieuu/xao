#include "core/LatestFrameBuffer.h"

#include <catch2/catch_test_macros.hpp>

#include <thread>

using asciicam::core::LatestFrameBuffer;

TEST_CASE("wait_pop returns a pushed value", "[buffer]") {
    LatestFrameBuffer<int> buf;
    buf.push(42);
    const auto v = buf.wait_pop();
    REQUIRE(v.has_value());
    CHECK(*v == 42);
}

TEST_CASE("newest value wins and stale values are counted as dropped", "[buffer]") {
    LatestFrameBuffer<int> buf;
    buf.push(1);
    buf.push(2);
    buf.push(3);  // overwrites 1 and 2

    const auto v = buf.wait_pop();
    REQUIRE(v.has_value());
    CHECK(*v == 3);
    CHECK(buf.dropped() == 2);
}

TEST_CASE("try_pop is non-blocking and empties the slot", "[buffer]") {
    LatestFrameBuffer<int> buf;
    CHECK_FALSE(buf.try_pop().has_value());
    buf.push(7);
    CHECK(buf.try_pop().value() == 7);
    CHECK_FALSE(buf.try_pop().has_value());
}

TEST_CASE("wait_pop returns nullopt once closed and empty", "[buffer]") {
    LatestFrameBuffer<int> buf;
    buf.close();
    CHECK_FALSE(buf.wait_pop().has_value());
}

TEST_CASE("producer/consumer never deadlocks and conserves every frame", "[buffer][threaded]") {
    LatestFrameBuffer<int> buf;
    constexpr int kCount = 5000;

    std::thread producer([&] {
        for (int i = 1; i <= kCount; ++i) {
            buf.push(i);
        }
        buf.close();
    });

    int consumed = 0;
    int last = -1;
    while (auto v = buf.wait_pop()) {
        last = *v;
        ++consumed;
    }
    producer.join();

    // The final push (kCount) is never overwritten, so it must be observed.
    CHECK(last == kCount);
    // Every produced frame was either consumed exactly once or dropped exactly once.
    CHECK(consumed + static_cast<int>(buf.dropped()) == kCount);
}
