#include "../common/types.h"

extern u8 D_004f4240[];

// FUN_001671e8 (44 bytes)
// Code: a0 = max(a0, 15000). In the record at D_004f4240: byte 1 = a1 & 0xff, byte 0 = 1,
//       word at +4 = the clamped a0.
// Guess: sets a clamped timer/value and a small mode byte in a fixed global record.
// Note: the record is a separate symbol, so gcc emits one `lui` (%hi) with the byte-0 store using
//       %lo(D_004f4240)(base) and `addiu p,base,%lo` for the other two stores, as the original does.
//       Pins ($15 constant, $13 compare, $14 pointer) and empty asm barriers give the original
//       order; `if (c) a0 = k` makes the movn.
void func_001671e8(s32 a0, s32 a1) {
    register s32 k asm("$15") = 15000;
    register s32 c asm("$13");
    register u8* p asm("$14");
    __asm__ volatile("" : "+r"(k));
    c = a0 < 15000;
    __asm__ volatile("" : "+r"(c));
    p = D_004f4240;
    if (c) a0 = k;
    __asm__ volatile("" : "+r"(p));
    u32 x = a1 & 0xff;
    __asm__ volatile("" : "+r"(x));
    k = 1;
    __asm__ volatile("" : "+r"(k));
    p[1] = (u8)x;
    __asm__ volatile("" ::: "memory");
    D_004f4240[0] = (u8)k;
    __asm__ volatile("" ::: "memory");
    *(s32*)(p + 4) = a0;
}

// FUN_00168ad8 (96 bytes)
// Code: *a1 = 0. For each of the n records (n at +4 of a0; 16-byte records, first one at +16):
//       if (a2 == -1 || halfword at +16 of the record == a2) and the word at +20 == a3,
//       increment *a1 (and reload n, since *a1 may alias it).
// Guess: counts the entries of a small table that match an id (or any id) and a value.
// Note: the shifted offset sits in $13 and each of the two paths re-adds a0 after its own empty
//       volatile "+r" barrier (so the addu is not hoisted above the first `beq` and the `sll`
//       lands in its delay slot). The goto chain keeps the original block order.
void func_00168ad8(u8* a0, s32* a1, s32 a2, s32 a3) {
    register s32 i asm("$12");
    register s32 n asm("$11");
    register s32 m asm("$10");
    register u32 off asm("$13");
    register u8* e asm("$15");
    register u32 v asm("$14");
    *a1 = 0;
    n = *(s32*)(a0 + 4);
    i = 0;
    if (n > 0) {
        m = -1;
        __asm__ volatile("" : "+r"(m));
        do {
            off = i << 4;
            if (a2 == m) goto B;
            __asm__ volatile("" : "+r"(off));
            e = (u8*)(off + (u32)a0);
            v = *(u16*)(e + 16);
            if (v != (u32)a2) goto C;
        B:
            __asm__ volatile("" : "+r"(off));
            e = (u8*)(off + (u32)a0);
            v = *(u32*)(e + 20);
            if (v == (u32)a3) {
                (*a1)++;
                n = *(s32*)(a0 + 4);
            }
        C:
            i++;
        } while (i < n);
    }
}
