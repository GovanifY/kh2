#include "../common/types.h"

u32 func_002b6708(u32, u32, u32);

// FUN_002b7fbc (64 bytes)
// Code: return func_002b6708(2, 50, a0);
// Guess: thin wrapper. -O0 frame; this file is built with -O0 via a
// target-specific CXXFLAGS line in the Makefile.
u32 func_002b7fbc(u32 a0) {
    return func_002b6708(2, 50, a0);
}
