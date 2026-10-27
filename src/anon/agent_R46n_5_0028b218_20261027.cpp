#include "../common/types.h"

// FUN_0028b218 (44 bytes)
// Code: store the low byte of a1 at +39; set bits 12..13 of the word at +52 if the byte is non-zero, else clear them.
// Guess: set a flag byte with a matching bit pair in a status word.
void func_0028b218(u32 a0, u32 a1) {
    u8 b = (u8)a1;
    *(u8*)(a0 + 39) = b;
    if (b) {
        u32 w = *(u32*)(a0 + 52);
        w |= 0x3000;
        *(u32*)(a0 + 52) = w;
    } else {
        u32 w = *(u32*)(a0 + 52);
        w &= ~0x3000u;
        *(u32*)(a0 + 52) = w;
    }
}
