#pragma once

#include "xao/Engine.h"
#include <vector>

namespace xao {

class Pipeline {
public:
    void render(const Image& source, Image& destination,
                const std::vector<EnginePass>& passes,
                const RenderContext& context) const;
};

} // namespace xao
