#include "wm_total_info.hpp"

namespace dk {
extern u32 D_00375540 asm("D_00375540");
extern u32 D_00361a90 asm("D_00361a90");


s32 WM_TOTAL_INFO::getBaseNum(s32 index) {
    return (s32)(*(s16*)((u32)&D_00375540 + ((u32)index << 1)));
}

void WM_TOTAL_INFO::exit() {
    u32 ptr = D_00361a90;
    if (ptr) {
        reinterpret_cast<WM_TOTAL_INFO*>(ptr)->fadeout();
        D_00361a90 = 0;
    }
}
}  // namespace dk
