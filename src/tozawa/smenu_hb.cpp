#include "types.h"

struct TASK;

namespace Tz {

extern u32 D_0035eda4 asm("D_0035eda4");
extern "C" void func_002430d8(u32);
extern "C" void func_00102448(u32, u32);
extern "C" void func_0024b588();
extern "C" void func_00242678(u32);
extern "C" void func_00236d60();
extern "C" u32 func_0024bd90();
extern "C" void func_0024c1a8();

class HBTE {
public:
    static void PauseThread(TASK*);
};

void HBTE::PauseThread(TASK* a0) {
    u32 s0 = (u32)a0;
    func_002430d8(D_0035eda4);
    func_00102448(s0, 1);
    func_0024b588();
    func_00242678(5014);
    while (1) {
        func_00236d60();
        if (func_0024bd90() != 0) {
            return;
        }
        func_0024c1a8();
        func_00102448(s0, 0);
    }
}

}  // namespace Tz
