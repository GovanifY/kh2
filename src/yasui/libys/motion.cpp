#include "motion.hpp"

namespace YS {



u32 MOTION::is_no_motion() {
    u32 v = *(u32*)((u32)this + 12);
    return (v < 1u);
}

void MOTION::sync(MOTION* other) {
    u32 t7 = (u32)((s32)(u32)this + 148);
    u32 t6 = *(u32*)((u32)t7 + 4);
    if (t6 == 0u) {
        *(u32*)((u32)t7 + 4) = (u32)other;
        *(u32*)((u32)this + 148) = (u32)other;
        *(u32*)((u32)other + 156) = 0u;
        return;
    }
    *(u32*)((u32)t6 + 156) = (u32)other;
    *(u32*)((u32)other + 156) = 0u;
    *(u32*)((u32)t7 + 4) = (u32)other;
}

}  // namespace YS
