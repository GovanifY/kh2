#include "../common/types.h"

u32 func_002b6708(u32, u32, u32, u32);

// FUN_002b83ec (72 bytes)
// Code: return func_002b6708(3, 38, a0, a1);
// Guess: thin wrapper. -O0 frame; this file is built with -O0 via a
// target-specific CXXFLAGS line in the Makefile.
u32 func_002b83ec(u32 a0, u32 a1) {
    return func_002b6708(3, 38, a0, a1);
}
