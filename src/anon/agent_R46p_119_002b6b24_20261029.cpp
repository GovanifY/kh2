#include "../common/types.h"

u32 func_002b6708(u32, u32, u32, u32, u32, u32, u32);

// FUN_002b6b24 (96 bytes)
// Code: return func_002b6708(6, 7, a0, a1, a2, a3, a4);
// Five args arrive in a0-a3 and t0; the callee gets seven. Built at -O0
// (frame pointer, args spilled to s8 slots); see the Makefile line.
u32 func_002b6b24(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    return func_002b6708(6, 7, a0, a1, a2, a3, a4);
}
