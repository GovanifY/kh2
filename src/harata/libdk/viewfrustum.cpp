#include "viewfrustum.hpp"

namespace kn {
class FMatrix;
}

namespace dk {



u32 ViewFrustum::setMatrix(const kn::FMatrix&) { return (u32)((s32)(u32)this + (128)); }

}  // namespace dk
