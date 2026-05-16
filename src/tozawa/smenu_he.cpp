#include "types.h"

struct TASK;

namespace Tz {

extern u32 D_0035ece4 asm("D_0035ece4");
extern "C" void func_002430d8(u32);
extern "C" void func_00102448(u32, u32);
extern "C" void func_00243740();
extern "C" void func_00236d60();
extern "C" u32 func_00244068();
extern "C" void func_002444b8();

class HEFT {
public:
    static void PauseThread(TASK*);
};

void HEFT::PauseThread(TASK* a0) {
    u32 s16 = (u32)a0;
    func_002430d8(D_0035ece4);
    func_00102448(s16, 1);
    func_00243740();
    while (1) {
        func_00236d60();
        if (func_00244068() != 0) {
            return;
        }
        func_002444b8();
        func_00102448(s16, 0);
    }
}

}  // namespace Tz
