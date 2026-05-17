#include "smenu_heco.hpp"

namespace Tz {

extern u32 D_0035ed18 asm("D_0035ed18");
extern u32 D_0035ed1c asm("D_0035ed1c");
extern "C" u32 func_00246840(u32);
extern "C" void func_002430d8(u32);
extern "C" void func_00102448(u32, u32);
extern "C" void func_00245488();
extern "C" void func_00236d60();
extern "C" u32 func_00245dd0();
extern "C" void func_00246328();

void HECO::PauseThread(TASK* a0) {
    u32 s0 = (u32)a0;
    if (func_00246840((u32)a0) != 0) {
        func_002430d8(D_0035ed1c);
    } else {
        func_002430d8(D_0035ed18);
    }

    func_00102448(s0, 1);
    func_00245488();

    while (1) {
        func_00236d60();
        if (func_00245dd0() != 0) {
            return;
        }
        func_00246328();
        func_00102448(s0, 0);
    }
}

}  // namespace Tz
