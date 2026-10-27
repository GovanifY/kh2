#include "../common/types.h"

extern u8 D_00360000[];
extern "C" void func_00139d78(u32) asm("_Z16u_call4_00139d78jjjj");

// FUN_00276f38 (36 bytes): passes *(*(D_00360000 - 3556)) + 408 to FUN_00139d78.
void func_00276f38(void) {
    u8* p = *(u8**)(D_00360000 - 3556);
    func_00139d78((u32)(p + 408));
    __asm__ volatile("" ::: "memory");
}
