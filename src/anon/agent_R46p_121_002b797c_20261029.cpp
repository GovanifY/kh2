#include "../common/types.h"

u32 func_002b6708(u32, u32, u32, u32, u32);

// FUN_002b797c (80 bytes)
// Code: return func_002b6708(4, 28, a0, a1, a2);
// Guess: thin wrapper, same shape as FUN_002b792c with a different second
// constant. Built -O0 via a per-object Makefile flag.
u32 func_002b797c(u32 a0, u32 a1, u32 a2) {
    return func_002b6708(4, 28, a0, a1, a2);
}
