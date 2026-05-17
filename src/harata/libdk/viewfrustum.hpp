#ifndef KH2_SRC_HARATA_LIBDK_VIEWFRUSTUM_HPP
#define KH2_SRC_HARATA_LIBDK_VIEWFRUSTUM_HPP

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

#endif
