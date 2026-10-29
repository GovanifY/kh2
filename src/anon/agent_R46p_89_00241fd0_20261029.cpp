#include "../common/types.h"

// FUN_00241fd0 (52 bytes): stores a1 at a0+0, allocates 1024 bytes with _Znaj,
// stores the pointer at a0+4, then tail-calls func_00242088(a0).
// The pointer-typed "+r" barrier keeps a0 in one copy (s0), giving the original order.
extern "C" void* znaj_001063f0(u32 n) asm("_Znaj");
extern "C" u32 func_00242088(u32 a0);

u32 func_00241fd0(u32 a0, u32 a1) {
    u32 *p = (u32 *)a0;
    asm volatile("" : "+r"(p));
    p[0] = a1;
    p[1] = (u32)znaj_001063f0(1024);
    return func_00242088((u32)p);
}
