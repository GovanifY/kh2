#include "smenu_mu.hpp"

namespace Tz {

extern u32 D_0035ed48 asm("D_0035ed48");
extern "C" void func_002430d8(u32);
extern "C" void func_00102448(u32, u32);
extern "C" void func_00248060();
extern "C" void func_00236d60();
extern "C" u32 func_00248900();
extern "C" void func_00248d28();

void MUMI::PauseThread(TASK* a0) {
    u32 s0 = (u32)a0;
    func_002430d8(D_0035ed48);
    func_00102448(s0, 1);
    func_00248060();
    while (1) {
        func_00236d60();
        if (func_00248900() != 0) {
            return;
        }
        func_00248d28();
        func_00102448(s0, 0);
    }
}

}  // namespace Tz
