#include "../common/types.h"

// Data symbols used below. D_00330000 and D_01d60000 are already in functions.tsv.
extern u8 D_00330000[];
extern u8 D_01d60000[];

// FUN_001d9d48 (64 bytes)
// Code: reads two bytes from a0 (a0[0] = index, a0[1] = bit number). The index selects a
//       32-bit word at D_00330000-8240 + 8*a0[0] + 4*(a0[1]>>5). Returns 1 when bit (a0[1]&31)
//       of that word is set, else 0.
// Guess: a bit-flag lookup in a per-object table, returning a boolean.
// Matching: the table address is written as &D_00330000[-8240] so the linker gets one
//       HI16/LO16 pair with an addend. The lui and addiu are split into two inline asm pieces
//       with barriers between them, because GCC places the addiu after the byte load and
//       the original keeps the lui before the second lbu. The other steps use pinned
//       registers, and the barriers keep the original instruction order.
u32 func_001d9d48(u8* a0) {
    register u32 t3 asm("$11");
    register u32 t4 asm("$12");
    register u32 t5 asm("$13");
    register u32 t6 asm("$14");
    register u32 t7 asm("$15");
    register u32 v0 asm("$2");
    t3 = a0[1];
    __asm__ volatile("" : "+r"(t3));
    __asm__ volatile("lui %0, %%hi(D_00330000-8240)" : "=r"(t7));
    t5 = a0[0];
    __asm__ volatile("" : "+r"(t5));
    __asm__ volatile("addiu %0, %0, %%lo(D_00330000-8240)" : "+r"(t7));
    t4 = t3 >> 5;
    __asm__ volatile("" : "+r"(t4));
    t6 = 1;
    __asm__ volatile("" : "+r"(t6));
    t5 <<= 3;
    t4 <<= 2;
    t5 += t7;
    __asm__ volatile("" : : "r"(t7));
    t3 &= 31;
    __asm__ volatile("" : "+r"(t3));
    t4 += t5;
    __asm__ volatile("" : : "r"(t5));
    t6 <<= t3;
    __asm__ volatile("" : "+r"(t6));
    v0 = *(u32*)(t4 + 0);
    v0 &= t6;
    __asm__ volatile("" : : "r"(t6));
    return (u32)(v0 != 0);
}

// FUN_001d9dd0 (92 bytes)
// Code: searches the table at D_01d60000-17752. The table has a count at +4 and 10-byte
//       records from +8. Returns the first record whose bytes +4, +5 and +6 equal a0, a1 and a2,
//       or 0 when none matches (or the count is not positive).
// Guess: a three-key search over a fixed-size record table.
// Matching: the lui and the table-pointer lw are one asm pair with %hi/%lo, so the lui comes
//       before the move that clears the counter. The counter is pinned to t5 with a barrier,
//       the pointer to t6 and the count to t7. The t6 += 8 runs before the test, so GCC fills
//       the blez delay slot with it, as in the original.
u32 func_001d9dd0(u32 a0, u32 a1, u32 a2) {
    register s32 t4 asm("$12");
    register s32 t5 asm("$13");
    register u32 t6 asm("$14");
    register u32 t7 asm("$15");
    register u32 v0 asm("$2");
    __asm__ volatile("lui %0, %%hi(D_01d60000-17752)" : "=r"(t7));
    t5 = 0;
    __asm__ volatile("" : "+r"(t5));
    __asm__ volatile("lw %0, %%lo(D_01d60000-17752)(%1)" : "=r"(t6) : "r"(t7));
    t7 = *(u32*)(t6 + 4);
    t6 = t6 + 8;

    if ((s32)t7 > 0) {
        t4 = (s32)t7;

        while (1) {
            if (*(u8*)(t6 + 4) == a0) {
                if (*(u8*)(t6 + 5) == a1) {
                    if (*(u8*)(t6 + 6) == a2) {
                        v0 = t6;
                        return v0;
                    }
                }
            }
            t5 = t5 + 1;
            if (t5 < t4) {
                t6 = t6 + 10;
            } else {
                break;
            }
        }
    }
    v0 = 0;
    return v0;
}

// FUN_001d9e30 (68 bytes)
// Code: if a0 is zero, returns table + 8 (the first record slot). Otherwise returns a0 + 10
//       when that is below the table end (table + count*10 + 8), or 0 when it is not.
// Guess: a cursor step over the same record table, returning NULL past the end.
// Matching: plain C. The C form already gives the original's two lui, lw and the
//       movn return. The file is built with -falign-functions=1 (see the Makefile line) so the
//       object has no padding nop after the 68-byte body.
u32 func_001d9e30(u32 a0) {
    if (a0 == 0) {
        u32 t = *(u32*)(D_01d60000 - 17752);
        return t + 8;
    }
    u32 tb = *(u32*)(D_01d60000 - 17752);
    u32 n = *(u32*)(tb + 4);
    u32 end = tb + n * 10 + 8;
    a0 += 10;
    return (a0 < end) ? a0 : 0;
}
