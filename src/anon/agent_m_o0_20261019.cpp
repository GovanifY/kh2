#include "../common/types.h"

u32 func_002b6708(u32, u32, u32);

// FUN_002b7efc (64 bytes)
// Code: return func_002b6708(2, 47, a0);
// Guess: thin wrapper. The original was compiled at -O0 (frame pointer,
// a0 spilled, result moved through t7); this file is built with -O0 via a
// target-specific CXXFLAGS line in the Makefile.
u32 func_002b7efc(u32 a0) {
    return func_002b6708(2, 47, a0);
}
