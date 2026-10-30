#include "../common/types.h"

u32 func_002b6708(u32, u32, u32, u32);

// FUN_002b7ca4 (72 bytes)
// Code: return func_002b6708(3, 30, a0, a1);
// Guess: two-argument thin wrapper. Built -O0 via a per-object Makefile flag.
u32 func_002b7ca4(u32 a0, u32 a1) {
    return func_002b6708(3, 30, a0, a1);
}
