#include "types.h"

struct TASK;

namespace Tz {

extern u32 D_0035ee00 asm("D_0035ee00");
extern "C" void func_002430d8(u32);
extern "C" void func_00102448(u32, u32);
extern "C" void func_0024e850();
extern "C" u32 func_0024ebc0();
extern "C" void func_0024edd8();

class TTMY {
public:
    static void PauseThread(TASK*);
};

void TTMY::PauseThread(TASK* a0) {
    u32 s0 = (u32)a0;
    func_002430d8(D_0035ee00);
    func_00102448(s0, 1);
    func_0024e850();
    while (1) {
        if (func_0024ebc0() != 0) {
            return;
        }
        func_0024edd8();
        func_00102448(s0, 0);
    }
}

}  // namespace Tz
