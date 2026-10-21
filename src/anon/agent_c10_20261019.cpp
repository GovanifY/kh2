#include "../common/types.h"

extern u8 D_00360000[];
extern u8 D_00370000[];

// FUN_00239f78 (88 bytes)
// Code: reads the float at a0+0x134 and the float at a0+0x138, and stores the
// float argument a1 at a0+0x13c. The three values are compared with the float
// constant at D_00370000+5320. Flag = 0 only when all three equal the constant,
// otherwise 1. The flag goes to bit 1 of the word at a0+0xb8 (bit 1 cleared,
// then set from the flag). Returns void.
// Guess: the same "all three zero" status update as FUN_00239e60, but one
// value is read from memory rather than from an argument.
// Build: the lui/addiu pair is in asm (so the constant address is one lui +
// addiu), and empty barriers keep the load order and the -3 mask after the
// status word load.
void func_00239f78(u8* a0, f32 a1) {
    register u32 t5 asm("$13");
    register u32 t6 asm("$14");
    register u32 t7 asm("$15");
    register f32* zp asm("$15");
    f32 m0;
    f32 m1;
    f32 z;
    __asm__ volatile("lui %0,%%hi(D_00370000+5320)" : "=r"(zp));
    m0 = *(f32*)(a0 + 0x134);
    __asm__ volatile("addiu %0,%0,%%lo(D_00370000+5320)" : "+r"(zp));
    *(f32*)(a0 + 0x13c) = a1;
    z = *zp;
    __asm__ volatile("" ::: "memory");
    t5 = 0;
    if (m0 != z) goto Lone;
    m1 = *(f32*)(a0 + 0x138);
    if (m1 != z) goto Lone;
    if (a1 == z) goto Lset;
Lone:
    t5 = 1;
Lset:
    t7 = *(u32*)(a0 + 0xb8);
    __asm__ volatile("" ::: "memory");
    t6 = (u32)-3;
    __asm__ volatile("" : "+r"(t6));
    t5 = t5 << 1;
    t7 = (t7 & t6) | t5;
    *(u32*)(a0 + 0xb8) = t7;
}

// FUN_002413f0 (96 bytes)
// Code: reads the table pointer at D_00360000-4972, and the signed byte at
// table+1 as a starting index i. Walks 32-byte records (table + i*32) while
// i < 99. A record is skipped when bit 0 of its byte at +8 is clear. When bit 0
// is set and bit 1 is clear, the function returns i. Otherwise it moves on.
// Returns -1 when the walk reaches 99 or starts at 99 or more.
// Guess: a find-first-ready-slot search over the 99 entries of a table, where
// "ready" means bit 0 set and bit 1 clear in the entry's status byte.
// Build: the pointer step is one addu in asm (rd=p, rs=offset, rt=p) to match
// the original operand order. The -1 and the final movn use register pins and
// a barrier so the return path matches (li in the beqz delay slot, movn in jr).
s32 func_002413f0(void) {
    register u8* p asm("$14");
    register s32 i asm("$13");
    register s32 t4 asm("$12");
    register s32 v0 asm("$2");
    register u32 t7 asm("$15");
    p = *(u8**)((u32)&D_00360000[0] - 4972u);
    __asm__ volatile("" : "+r"(p));
    i = (s8)p[1];
    t4 = i < 99;
    if (!t4) goto Lexit;
    t7 = (u32)i << 5;
    __asm__ volatile("addu %0,%1,%0" : "+r"(p) : "r"(t7));
Lloop:
    t7 = p[8];
    t7 = t7 ^ 1;
    t7 = t7 & 1;
    __asm__ volatile("" : "+r"(t7));
    t7 = t7 & 0xff;
    if (t7 != 0) { i++; goto Lcont; }
    t7 = *(u32*)(p + 8);
    t7 = t7 & 2;
    __asm__ volatile("" : "+r"(v0));
    v0 = -1;
    if (t7 == 0) goto Lfin;
    i++;
Lcont:
    t4 = i < 99;
    if (t4) { p += 32; goto Lloop; }
Lexit:
    v0 = -1;
Lfin:
    if (t4) v0 = i;
    return v0;
}

// FUN_00241a00 (68 bytes)
// Code: starts at the record at table+8 of the same table as FUN_002413f0
// (pointer at D_00360000-4972) and steps by 32 bytes for 99 records. Returns 1
// as soon as the word at a record's +0 has bit 4 (0x10) set. Otherwise returns 0.
// Guess: a "any entry has flag 0x10" check over the same 99-entry table.
// Build: the v0 = 0 and the base load are placed so the lui, move v0, lw,
// move i, addiu order matches the original. Needs -falign-functions=1 for
// this object (68 bytes is not a multiple of 8).
s32 func_00241a00(void) {
    register s32 v0 asm("$2");
    register u8* p asm("$14");
    register s32 i asm("$13");
    register u32 w asm("$15");
    p = *(u8**)((u32)&D_00360000[0] - 4972u);
    v0 = 0;
    __asm__ volatile("" : "+r"(v0), "+r"(p));
    i = 0;
    __asm__ volatile("" : "+r"(i));
    p = p + 8;
    do {
        w = *(u32*)p;
        p += 32;
        if (w & 0x10) { v0 = 1; goto Lret; }
        i++;
    } while (i < 99);
Lret:
    return v0;
}
