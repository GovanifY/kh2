#include "smenu_ttpt.hpp"

namespace Tz {

extern u32 D_0035edc8 asm("D_0035edc8");
extern "C" void func_002430d8(u32);
extern "C" void func_00102448(u32, u32);
extern "C" void func_0024ce18();
extern "C" void func_00236d60();
extern "C" u32 func_0024d6c8();
extern "C" void func_0024db28();

void TTPT::PauseThread(TASK* a0) {
    u32 s0 = (u32)a0;
    func_002430d8(D_0035edc8);
    func_00102448(s0, 1);
    func_0024ce18();
    while (1) {
        func_00236d60();
        if (func_0024d6c8() != 0) {
            return;
        }
        func_0024db28();
        func_00102448(s0, 0);
    }
}

}  // namespace Tz
