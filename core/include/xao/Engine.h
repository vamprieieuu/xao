#pragma once

#include "xao/Image.h"
#include <cstdint>

namespace xao {

struct RenderContext {
    double timeSeconds = 0.0;
    std::int64_t frame = 0;
    float renderScale = 1.0f;
    // Output resolution used by physical print-screen engines (e.g. LPI -> pixels).
    // Defaults to 300 DPI; AE adapters should override when a reliable comp/output DPI is available.
    float resolutionDpi = 300.0f;
    std::uint64_t seed = 0;
};

class Engine {
public:
    virtual ~Engine() = default;
    virtual const char* id() const noexcept = 0;
    // Source and destination have identical dimensions and use linear premultiplied RGBA.
    // Implementations must write every destination pixel on every call.
    virtual void render(const Image& source, Image& destination, const RenderContext& context) const = 0;
};

enum class CompositeMode {
    Mix,
    SourceOver
};

struct EnginePass {
    const Engine* engine = nullptr;
    bool enabled = true;
    float opacity = 1.0f;
    CompositeMode composite = CompositeMode::Mix;
};

} // namespace xao
