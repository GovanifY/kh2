#include "member.hpp"

namespace YS {

extern u8 D_0032bae0 asm("D_0032bae0");
extern u8 D_0032f064 asm("D_0032f064");



u32 MEMBER::Get(s32 index) {
    if (index < 0) {
        index = (s32)(u32)D_0032bae0;
    }
    return (u32)((u32)index << 2) + (u32)&D_0032f064;
}

extern "C" u32 func_001a9018(u32, u32);
u32 MEMBER::is_exist(s32 index) const {
    u32 r2 = func_001a9018((u32)this, (u32)index);
    r2 = (u32)(~(0u | r2));
    r2 = (u32)(r2 >> 31);
    return r2;
}

}  // namespace YS
