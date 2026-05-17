#include "wm_landing_info.hpp"

namespace dk {
extern u32 D_00361dd8 asm("D_00361dd8");

bool WM_LANDING::isListType() { return *(u32*)((u32)this + 8244) != 0; }

bool WM_LANDING::isEpisodeType() { return ((*(u32*)((u32)this + 8244) ^ 2u) == 0); }

void WM_LANDING_INFO::exit() {
    u32 ptr = D_00361dd8;
    if (ptr) {
        reinterpret_cast<WM_LANDING_INFO*>(ptr)->fadeout();
        D_00361dd8 = 0;
    }
}
}  // namespace dk
