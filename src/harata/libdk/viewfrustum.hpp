#pragma once

#include "../../common/types.h"

namespace kn {
class FMatrix;
}

namespace dk {

    class ViewFrustum {
    public:
        u32 setMatrix(const kn::FMatrix&);
    };

}  // namespace dk

