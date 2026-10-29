#include "../common/types.h"

// Callee: _Z16u_call4_00139d78jjjj, called here with its first two arguments only.
extern "C" void u_call4_00139d78(u32 a0, u32 a1) asm("_Z16u_call4_00139d78jjjj");

// FUN_0023f628 (52 bytes)
// Code: p = a0; u_call4(a0, a1); p->+64 = a1.
// The empty "+r" barrier on the pointer keeps the copy in s0, and the saved a1 lands in s1 so the
// move fills the jal delay slot as in the original.
void func_0023f628(u32 a0, u32 a1) {
    u32 *p = (u32 *)a0;
    asm volatile("" : "+r"(p));
    u_call4_00139d78(a0, a1);
    p[16] = a1;
}
