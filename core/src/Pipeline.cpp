#include "xao/Pipeline.h"
#include "xao/Compositor.h"

#include <stdexcept>
#include <utility>

namespace xao {

void Pipeline::render(const Image& source, Image& destination,
                      const std::vector<EnginePass>& passes,
                      const RenderContext& context) const {
    if (source.width() != destination.width() || source.height() != destination.height())
        throw std::invalid_argument("Pipeline source and destination dimensions must match");

    Image current = source;
    Image processed(source.width(), source.height());
    Image composed(source.width(), source.height());

    for (const EnginePass& pass : passes) {
        if (!pass.enabled || pass.engine == nullptr || pass.opacity <= 0.0f) continue;
        pass.engine->render(current, processed, context);
        if (pass.composite == CompositeMode::SourceOver)
            sourceOverPremultiplied(current, processed, composed, pass.opacity);
        else
            mixPremultiplied(current, processed, composed, pass.opacity);
        current = composed;
    }
    destination = std::move(current);
}

} // namespace xao
