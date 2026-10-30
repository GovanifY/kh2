#include "../common/types.h"

u32 func_002b6708(u32, u32, u32, u32, u32);

// FUN_002b792c (80 bytes)
// Code: return func_002b6708(4, 27, a0, a1, a2);
// Guess: thin wrapper. The original was compiled at -O0 (frame pointer,
// args spilled to the frame, result moved through t7); this file is built
// with -O0 via a per-object Makefile flag.
u32 func_002b792c(u32 a0, u32 a1, u32 a2) {
    return func_002b6708(4, 27, a0, a1, a2);
}
