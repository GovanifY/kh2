#include "wm_glanding_info.hpp"

namespace dk {
extern u32 D_00361e00 asm("D_00361e00");


void WM_GLANDING_INFO::exit() {
    u32 ptr = D_00361e00;
    if (ptr) {
        reinterpret_cast<WM_GLANDING_INFO*>(ptr)->fadeout();
        D_00361e00 = 0;
    }
}
}  // namespace dk
