#include "../common/types.h"

u32 func_002b6708(u32, u32);

// FUN_002b9a00 (56 bytes)
// Code: return func_002b6708(1, 42);
// Guess: thin wrapper. -O0 frame; this file is built with -O0 via a
// target-specific CXXFLAGS line in the Makefile.
u32 func_002b9a00(void) {
    return func_002b6708(1, 42);
}
