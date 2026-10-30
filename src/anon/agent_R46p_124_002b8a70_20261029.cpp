#include "../common/types.h"

void func_002b78ec(u32);

// FUN_002b8a70 (80 bytes)
// Code: func_002b78ec(a0 + 0x8000); *(u32 *)(a0 + 0x48000) = 0;
// Guess: a call on a sub-object at +0x8000, then clears a word at +0x48000.
// -O0 frame; this file is built with -O0 via a target-specific CXXFLAGS
// line in the Makefile.
void func_002b8a70(u32 a0) {
    func_002b78ec(a0 + 0x8000);
    *(u32 *)(a0 + 0x48000) = 0;
}
