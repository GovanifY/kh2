#include "types.h"

namespace kn {
class FMatrix;
}

namespace dk {

class ViewFrustum {
public:
    u32 setMatrix(const kn::FMatrix&);
};

u32 ViewFrustum::setMatrix(const kn::FMatrix&) { return (u32)((s32)(u32)this + (128)); }

}  // namespace dk
