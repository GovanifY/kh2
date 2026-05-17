#include "smenu_lm.hpp"

namespace Tz {

extern u32 D_0035ee30 asm("D_0035ee30");
extern "C" void func_002430d8(u32);
extern "C" void func_00102448(u32, u32);
extern "C" void func_0024f710();
extern "C" void func_00242678(u32);
extern "C" void func_00236d60();
extern "C" u32 func_0024ff08();
extern "C" void func_00250328();

void LMMU::PauseThread(TASK* a0) {
    u32 s0 = (u32)a0;
    func_002430d8(D_0035ee30);
    func_00102448(s0, 1);
    func_0024f710();
    func_00242678(12022);
    while (1) {
        func_00236d60();
        if (func_0024ff08() != 0) {
            return;
        }
        func_00250328();
        func_00102448(s0, 0);
    }
}

}  // namespace Tz
