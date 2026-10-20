#include "../common/types.h"

// FUN_001317a8 (88 bytes)
// Code: y = x * obj->sub->f[88] (sub = obj->ptr at +4); y = y / c1 + c2 (float constants
//       at 0x36abec and 0x36abf0); v = (int)y, clamped to >= 0; returns v if v < n,
//       else n - 1, where n = sub->word[36].
// Guess: maps a float parameter (a time or fraction) to an index into a table of n entries.
// Note: the asm barriers keep the original load/instruction order, and the constant
//       addresses are built as lui + addiu with a signed offset (no D_ symbol needed).
s32 func_001317a8(f32 x, u8* a0) {
    u8* sub = *(u8**)(a0 + 4);
    f32 k = *(f32*)(sub + 88);
    __asm__ volatile("" ::: "memory");
    register s32 n asm("$14");
    n = *(s32*)(sub + 36);
    __asm__ volatile("" ::: "memory");
    f32 y = x * k;
    __asm__ volatile("" ::: "memory");
    register u32 hi1 asm("$15");
    __asm__ volatile("lui %0,0x37" : "=r"(hi1));
    register s32 m asm("$13");
    m = n - 1;
    __asm__ volatile("" : "+r"(m));
    f32* pc1 = (f32*)(hi1 - 21524);
    __asm__("" : "+r"(pc1));
    register f32 c1 asm("$f0");
    c1 = *pc1;
    y = y / c1;
    register u32 hi2 asm("$15");
    __asm__ volatile("lui %0,0x37" : "=r"(hi2));
    f32* pc2 = (f32*)(hi2 - 21520);
    __asm__("" : "+r"(pc2));
    register f32 c2 asm("$f1");
    c2 = *pc2;
    y = y + c2;
    s32 v = (s32)y;
    if (v < 0)
        v = 0;
    return v < n ? v : m;
}

// FUN_001418e8 (64 bytes)
// Code: n = obj->word[36]. If n > 0, for each of the n entries of 20 bytes starting at
//       obj->ptr[8] (the base is re-read each pass): if byte 17 of the entry equals a1,
//       clear byte 16.
// Guess: "clear the flag on every record whose type matches", a bulk reset.
void func_001418e8(u8* a0, u8 a1) {
    s32 n = *(s32*)(a0 + 36);
    if (n > 0) {
        s32 i = n;
        s32 off = 0;
        do {
            u32 base = *(u32*)(a0 + 8);
            u8* e = (u8*)(off + base);
            if (e[17] == a1)
                e[16] = 0;
            off += 20;
            i--;
        } while (i != 0);
    }
}

// FUN_0014b920 (48 bytes)
// Code: writes four doublewords to arg0 in this order: [24] = 64, [0] = 0x1000000000008001,
//       [8] = 14, [16] = the 64-bit value at 0x36b0d0.
// Guess: initializer for a 32-byte record with a fixed tag, a count and a default value.
// Note: the store order is kept with empty asm barriers, and the 64-bit constant is pinned
//       to $14 so GCC uses the same temporary registers as the original.
void func_0014b920(u64* a0) {
    register u64 big asm("$14") = 0x1000000000008001ULL;
    register u64 t asm("$15") = 64;
    a0[3] = t;
    register u64 f asm("$15");
    f = 14;
    __asm__ volatile("" : "+r"(f));
    a0[0] = big;
    a0[1] = f;
    register u32 hi asm("$14") = 0x370000;
    __asm__("" : "+r"(hi));
    a0[2] = *(u64*)(hi - 20272);
}
