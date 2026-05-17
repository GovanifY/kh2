#include "smenu_cana.hpp"

namespace Tz {

extern u32 D_0035ee54 asm("D_0035ee54");
extern "C" void func_002430d8(u32);
extern "C" void func_00102448(u32, u32);
extern "C" void func_00251148();
extern "C" void func_00242678(u32);
extern "C" void func_00236d60();
extern "C" u32 func_00251318();
extern "C" void func_00251a70();

void CANA::PauseThread(TASK* a0) {
    u32 s0 = (u32)a0;
    func_002430d8(D_0035ee54);
    func_00102448(s0, 1);
    func_00251148();
    func_00242678(17014);
    while (1) {
        func_00236d60();
        if (func_00251318() != 0) {
            return;
        }
        func_00251a70();
        func_00102448(s0, 0);
    }
}

}  // namespace Tz
