#include "../common/types.h"

extern u8 D_00360000[];
extern "C" void func_00308650(void);

// FUN_00308cd0 (36 bytes): calls FUN_00308650(), then clears the word at D_00360000 + 24796.
void func_00308cd0(void) {
    register u8* p asm("$2");
    func_00308650();
    p = D_00360000;
    *(u32*)(p + 24796) = 0;
}
