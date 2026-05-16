#include "types.h"

namespace dk {
extern u32 D_00361e00 asm("D_00361e00");
class WM_GLANDING_INFO {
public:
    void fadeout();
    void exit();
};

void WM_GLANDING_INFO::exit() {
    u32 ptr = D_00361e00;
    if (ptr) {
        reinterpret_cast<WM_GLANDING_INFO*>(ptr)->fadeout();
        D_00361e00 = 0;
    }
}
}  // namespace dk
