#include "../common/types.h"

u32 func_002b6708(u32, u32);

// FUN_002b7f84 (56 bytes)
// Code: return func_002b6708(1, 49);
// Guess: thin wrapper with no arguments. The original was compiled at -O0
// (frame pointer, result moved through t7); this file is built with -O0 via a
// target-specific CXXFLAGS line in the Makefile.
u32 func_002b7f84(void) {
    return func_002b6708(1, 49);
}
