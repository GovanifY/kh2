#include "../common/types.h"

// Agent K: small leaf functions decompiled from SLPM_666.75.

extern u8 D_0032d7c0[];
extern u8 D_01d49388[];
extern f32 D_0036b210;

struct E12 { u32 a, b, c; };
struct T12 { u16 x; u16 n; E12 e[1]; };
extern T12* D_01c6cb98;

// FUN_001814b8 (68 bytes)
// Code: n selects a word in a bit table at 0x32D7C0: row (n >> 10) * 32 bytes,
// plus word ((n & 0x3ff) >> 5); clears bit (n & 0x1f) in that word.
// Guess: clears one flag bit in a two-level bitmap.
void func_001814b8(s32 n) {
    u8* r = D_0032d7c0 + ((n >> 10) << 5);
    n &= 0x3ff;
    u32 word = (u32)n >> 5;
    u32* p = (u32*)r + word;
    u32 bit = 1u << (n & 0x1f);
    *p = *p & ~bit;
}

// FUN_001c11e0 (56 bytes)
// Code: starts at 0x1D49388 + 320 and walks down in steps of 64 bytes for up to
// 5 entries; returns the first entry whose u16 at +0 is nonzero, else 0.
// Guess: finds the last used slot in a 6-slot table.
// The empty inline asm only stops the compiler folding the +320 into the symbol
// address (the original keeps a separate addiu for the offset).
u8* func_001c11e0(void) {
    u8* base = D_01d49388;
    __asm__("" : "+r"(base));
    u8* p = base + 320;
    for (s32 i = 5; i > 0; i--, p -= 64) {
        if (*(u16*)p) return p;
    }
    return 0;
}

// FUN_001a82b0 (64 bytes)
// Code: table pointer at 0x1C6CB98 has u16 count at +2 and 12-byte entries from
// +4. With a == 0 returns the first entry. Otherwise returns the next entry
// (a + 12) if it lies before the end of the table, else 0.
// Guess: iterator over a table of 12-byte entries ("next element or null").
// Two empty inline asm statements only pin the scheduling order: the first makes
// a+12 depend on the loaded table pointer, the second makes the count load come
// after it. r/end are pinned to v0/t7 to match the register allocation.
E12* func_001a82b0(E12* a) {
    if (a == 0) return D_01c6cb98->e;
    T12* t = D_01c6cb98;
    __asm__("" : "+r"(a) : "r"(t));
    register E12* r asm("$2") = a + 1;
    __asm__("" : "+r"(t) : "r"(r));
    register E12* end asm("$15") = t->e + t->n;
    register s32 c asm("$15") = r < end;
    if (!c) r = 0;
    return r;
}

// FUN_0014f030 (56 bytes)
// Code: out[0] = a; out[2] = b; out[1] = (b - a) / c, where c falls back to the
// float at 0x36B210 when it is 0.0.
// Guess: sets up a linear interpolation (start, step, end) with a default span.
// The empty inline asm keeps the constant address as lui+addiu followed by lwc1 0(reg).
void func_0014f030(f32* out, f32 a, f32 b, f32 c) {
    if (c == 0.0f) {
        f32* q = &D_0036b210;
        __asm__("" : "+r"(q));
        c = *q;
    }
    out[0] = a;
    out[2] = b;
    out[1] = (b - a) / c;
}

// FUN_002374c8 (64 bytes)
// Code: s+12 points to a table of 4-byte slots whose first u16 is a base index;
// s+8 points to an array of 20-byte records. e = rec[u16(slot i) + j]. Then
// e[+12] = v + e[+12] - e[+4]; e[+4] = v.
// Guess: sets a new value in a record and adjusts a running total by the delta.
void func_002374c8(u8* s, s32 i, s32 j, s32 v) {
    u16* arr = *(u16**)(s + 12);
    u8* e = *(u8**)(s + 8) + (*(u16*)((u8*)arr + i * 4) + j) * 20;
    s32 d = v + *(s32*)(e + 12) - *(s32*)(e + 4);
    *(s32*)(e + 4) = v;
    *(s32*)(e + 12) = d;
}
