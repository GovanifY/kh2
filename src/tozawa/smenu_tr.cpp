#include "smenu_tr.hpp"

namespace Tz {

extern u32 D_0035ed6c asm("D_0035ed6c");
extern "C" void func_002430d8(u32);
extern "C" void func_00102448(u32, u32);
extern "C" void func_002499b8();
extern "C" void func_00242678(u32);
extern "C" void func_00236d60();
extern "C" u32 func_0024a270();
extern "C" void func_0024a710();

void TRTE::PauseThread(TASK* a0) {
    u32 s0 = (u32)a0;
    func_002430d8(D_0035ed6c);
    func_00102448(s0, 1);
    func_002499b8();
    func_00242678(18014);
    while (1) {
        func_00236d60();
        if (func_0024a270() != 0) {
            return;
        }
        func_0024a710();
        func_00102448(s0, 0);
    }
}

}  // namespace Tz
