#include "../common/types.h"

// Batch agent_B: small leaf functions decompiled from SLPM_666.75.
// Each comment says what the code does, then gives a guess at its role.
// The guesses are unverified.

extern u8 D_00360000;

// FUN_0023d300 (32 bytes)
// Code: loads a 32-bit word from the global at 0x35eb4c (D_00360000 - 5300).
// If the word is -1 (0xffffffff), it stores 0 to *arg0 and returns 0.
// Otherwise it stores the word to *arg0 and returns 1.
// Guess: a "take pending value" helper. It uses -1 as an empty sentinel and
// returns whether the global holds a real value.
u32 func_0023d300(u32* a0) {
    u32 g = *(u32*)((u32)&D_00360000 - 5300u);
    u32 f = (g == 0xffffffffu);
    u32 r = f ? 0u : g;
    *a0 = r;
    return f ^ 1u;
}

// FUN_00314b38 (84 bytes)
// Code: decodes a variable-length integer from a byte stream. Each byte gives 7
// data bits (low bits first). Bit 0x80 means another byte follows. After the
// last byte, if the shift is below 64 and that byte has bit 0x40 set, the
// upper bits are filled with ones (sign extension). The 64-bit result goes to
// *arg1. The return value is the pointer just past the last byte read.
// Guess: an LEB128-style signed integer reader for a binary file or stream.
const u8* func_00314b38(const u8* a0, u64* a1) {
    const u8* p = a0;
    s32 t4 = 0;
    s64 t3 = 0;
    u8 t5;
    do {
        t5 = *p++;
        s32 t7 = (s32)(t5 & 0x7f) << t4;
        t3 = t3 | (s64)t7;
        t4 += 7;
    } while (t5 & 0x80);
    if ((u32)t4 < 64u && (t5 & 0x40)) {
        t3 = t3 | ((s64)-1 << t4);
    }
    *a1 = (u64)t3;
    return p;
}

// FUN_002b16d8 (44 bytes)
// Code: reads a global pointer from 0x35f634 (D_00360000 - 2508). It reads the
// word at +22012 and compares it with 126. If equal, it returns 1 when the
// word at +23292 is 0x81, otherwise 0. If not equal, it returns 0.
// Guess: a state check on a runtime object. Value 126 looks like a type or
// state tag, and 0x81 looks like a second tag. The exact meaning is unknown.
u32 func_002b16d8(void) {
    u8* p = *(u8**)((u32)&D_00360000 - 2508u);
    s32 b = *(s32*)((u32)p + 22012u);
    s32 a = *(s32*)((u32)p + 23292u);
    u32 r = 0;
    if (b == 126) r = ((a ^ 0x81) == 0);
    return r;
}
