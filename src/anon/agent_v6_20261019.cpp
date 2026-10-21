#include "../common/types.h"

// Data words used by the functions below.
// D_01d5ba98 holds a pointer to a table. The table starts with a 32-bit count at +4 (scaled by 64).
extern u8* D_01d5ba98;
// D_0032fafe is a 16-bit counter at offset +2 (the original reads it with lhu at +2 of 0x0032fafe).
extern u8 D_0032fafe[];

// FUN_001d6cc8 (56 bytes)
// Code: if a0 is non-zero, returns a0+64 when it is below (table + (table->count << 6) + 8),
//       otherwise 0. If a0 is zero, returns table + 8.
// Guess: returns the next entry slot of a fixed-size table, or NULL when past the end.
// Matching: the null test is written with a pinned register for the table base, and the
//       asm block pins a0+64 before the table load, so GCC emits the original bnez/lui delay
//       slot and the movz return with no trailing epilogue.
u8* func_001d6cc8(u8* a0) {
    register u8** base asm("$15") = &D_01d5ba98;  // lui t7 (in the bnez delay slot)
    register u8* t6 asm("$14");
    register u8* v0 asm("$2");
    if (a0 == 0) {
        t6 = *base;  // lw t6,%lo(t7)
        return t6 + 8;
    }
    // addiu v0,a0,64. The asm stops GCC from moving it into the branch delay slot.
    __asm__ volatile("addiu %0,%1,64" : "=r"(v0) : "r"(a0) : "memory");
    register u32 t5 asm("$13");
    t6 = *base;                           // lw t6,%lo(t7)
    t5 = *(u32*)((u8*)t6 + 4);            // lw t5,4(t6)
    t6 = t6 + (t5 << 6) + 8;              // sll, addu, addiu
    register u32 c asm("$14") = ((u32)v0 < (u32)t6);  // sltu (result reuses t6)
    return c ? v0 : 0;                    // movz v0,zero,t6
}

// FUN_001d7f40 (60 bytes; the object is built with -falign-functions=1 so no trailing padding)
// Code: reads a count n at a0[0]. Scans n records of 68 bytes (bytes at a0+4, a0+72, ...)
//       for the byte value a1. Returns the index of the first match, or -1.
// Guess: finds a byte key in a table of 68-byte entries and returns its index.
s32 func_001d7f40(u8* a0, u32 a1) {
    register s32 n asm("$12") = *(s32*)a0;   // lw t4,0(a0)
    register s32 i asm("$13") = 0;           // move t5,zero
    register u8* p asm("$4");
    register u32 b asm("$15");
    register s32 k asm("$2");
    if (n > 0) {
        p = a0 + 4;                          // addiu a0,a0,4
        do {
            b = *p;                          // lbu t7,0(a0)
            k = i;                           // move v0,t5
            // Empty barrier keeps the k copy before the increment, as in the original.
            __asm__ volatile("" ::: "memory");
            i = i + 1;                       // addiu t5,t5,1
            p = p + 68;                      // addiu a0,a0,68
            if (b == a1) return k;           // beq t7,a1
        } while (i < n);                     // slt t6,t5,t4 ; bnezl t6
    }
    return -1;                               // li v0,-1
}

// FUN_001d97c8 (40 bytes)
// Code: t = *(u16*)(0x0032fafe+2). Stores t+1 back if t < 999 (unsigned). Otherwise leaves it.
// Guess: a saturating 16-bit counter (counts up to 999) at 0x0032fb00.
void func_001d97c8() {
    register u8* base asm("$14") = D_0032fafe;      // lui t6 / addiu t6
    register u32 t7 asm("$15") = *(u16*)(base + 2); // lhu t7,2(t6)
    register u32 t5 asm("$13") = t7 + 1;            // addiu t5,t7,1
    __asm__ volatile("andi %0,%0,0xffff" : "+r"(t7));  // andi t7,t7,0xffff (kept so GCC does not drop it)
    if (t7 < 999) {                                 // sltiu t7,t7,999 ; bnezl
        *(u16*)(base + 2) = (u16)t5;                // sh t5,2(t6) in the delay slot
    }
}
