#include "../common/types.h"

extern u8 D_01c6cb98[];
extern u8 D_01c6cba0[];
extern u32 D_0036d61c[];

// FUN_001a8258 (84 bytes)
// Code: reads the record table pointer at the global word 0x01c6cb98. Each record
// is 12 bytes starting at table+4; the u16 count is at table+2. Returns the first
// record whose u16 id at +0 equals a0 and whose byte at +4 is 1, or 0.
// Guess: lookup of an entry by id in a fixed-size record table.
// Written with a do-while (count in t4, index in t5) and a shared exit through the
// volatile asm zeroing v0. The count load and the index zeroing are pinned with
// register variables and volatile asm so the scheduler puts them in the same order
// as the original, and the pointer add lands in the beqz delay slot.
u8* func_001a8258(s32 a0) {
    register s32 hi asm("$15");
    register u8* base asm("$14");
    register s32 i asm("$13");
    register s32 cnt asm("$12");
    register s32 n asm("$15");
    register u8* r asm("$2");
    __asm__ volatile("lui %0,%%hi(D_01c6cb98)" : "=r"(hi));
    __asm__ volatile("move %0,$0" : "=r"(i));
    __asm__ volatile("lw %0,%%lo(D_01c6cb98)(%1)" : "=r"(base) : "r"(hi));
    n = *(u16*)(base + 2);
    u8* p = base + 4;
    if (n == 0) goto zero;
    __asm__ volatile("move %0,%1" : "=r"(cnt) : "r"(n));
    do {
        if (*(u8*)(p + 4) == 1 && *(u16*)p == a0) { r = p; goto out; }
        i++;
        p += 12;
    } while (i < cnt);
zero:
    __asm__ volatile("move %0,$0" : "=r"(r));
out:
    return r;
}

// FUN_001a8510 (52 bytes)
// Code: two words at global 0x01c6cba0 (A at +0, B at +4). x = A - B, y = x + 8;
// returns y % 8 in C signed semantics (the quotient is computed with the usual
// y<0 ? y+7 : y adjustment through movz).
// Guess: a wrap-around offset or phase of a timer / animation counter; the result is
// the remainder of (A - B + 8) by 8.
// The address is set with a hand-written lui/addiu/lw triple (paired %hi/%lo of the
// same symbol) so the pointer is computed with addiu and the first load uses the lui.
// The quotient shift is an asm sra and the final subtract sits in the jr delay slot.
s32 func_001a8510(void) {
    register s32 h asm("$13");
    register s32* p asm("$12");
    register s32 x asm("$15");
    __asm__ volatile("lui %0,%%hi(D_01c6cba0)" : "=r"(h));
    __asm__ volatile("addiu %0,%1,%%lo(D_01c6cba0)" : "=r"(p) : "r"(h));
    __asm__ volatile("lw %0,%%lo(D_01c6cba0)(%1)" : "=r"(x) : "r"(h));
    x = x - p[1];
    s32 y = x + 8;
    s32 t = x + 15;
    if (y >= 0) t = y;
    register s32 tt asm("$15") = t;
    register s32 q asm("$2");
    __asm__ volatile("sra %0,%1,3" : "=r"(q) : "r"(tt));
    register s32 w asm("$14");
    __asm__ volatile("sll %0,%1,3" : "=r"(w) : "r"(q));
    register s32 res asm("$2");
    __asm__ volatile("subu %0,%1,%2" : "=r"(res) : "r"(y), "r"(w));
    return res;
}

// FUN_001a9a28 (64 bytes)
// Code: if a0 < 6, jumps through the existing table at 0x0036d61c (entries are code
// addresses; case 1 subtracts *a1 from *a2 and stores it back; cases 0 and the rest
// return). Otherwise returns.
// Guess: a 6-way per-kind update (kind 1 is "subtract a delta from a value").
// Written as a computed goto through the existing table. The labels are kept by an
// empty asm so the block layout matches the original.
void func_001a9a28(u32 a0, s32* a1, s32* a2) {
    __asm__ volatile("" :: "X"(&&L1), "X"(&&Lret));
    if (a0 >= 6) goto Lret;
    goto *(void*)D_0036d61c[a0];
L1:
    {
        s32 x = *a1;
        s32 y = *a2;
        *a2 = y - x;
    }
    return;
Lret:
    return;
}
