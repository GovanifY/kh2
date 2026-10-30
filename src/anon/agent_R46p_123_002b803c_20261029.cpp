#include "../common/types.h"

u32 func_002b6708(u32, u32, u32);

// FUN_002b803c (64 bytes)
// Code: return func_002b6708(2, 52, a0);
// Guess: thin wrapper. -O0 frame; this file is built with -O0 via a
// target-specific CXXFLAGS line in the Makefile.
u32 func_002b803c(u32 a0) {
    return func_002b6708(2, 52, a0);
}
