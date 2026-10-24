#include "../common/types.h"

// FUN_0016dbe0 (68 bytes)
// Code: r = FUN_00167f18(0); w = the doubleword at +8 of r; reads the word at
// +0 of arg0 as a shift count; stores (w >> count) & 1 back to +0 of arg0.
// Guess: a bit test on a 64-bit flag word returned by the menu cursor.
u32 func_00167f18(u32 a0);

void func_0016dbe0(u32* a0) {
    u64* p = (u64*)(func_00167f18(0u) + 8u);
    u32 sh = *a0;
    u64 w = *p;
    u64 b = (w >> sh) & 1ull;
    u8 r = (u8)b;
    *a0 = r;
}
