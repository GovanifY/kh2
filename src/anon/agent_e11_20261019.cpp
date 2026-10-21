#include "../common/types.h"

// FUN_001bc948 (68 bytes)
// Code: n = word at +8 of a0. If n <= 0, returns 0. Otherwise walks n records of 12 bytes
//       starting at a0+17; returns 1 as soon as the byte at the record is < 4, else 0.
// Build: u32 c with an "+r" barrier on c and p gives the sltiu/andi pair and keeps the p += 12
//        increment in the bnez delay slot.
u32 func_001bc948(u8* a0) {
    s32 n = *(s32*)(a0 + 8);
    s32 i = 0;
    u8* p;
    u32 r;
    if (n > 0) {
        p = a0 + 17;
        do {
            u32 c = *p < 4;
            asm("" : "+r"(c), "+r"(p));
            u8 d = c;
            if (d) { r = 1; goto done; }
            p += 12;
            i++;
        } while (i < n);
    }
    r = 0;
done:
    return r;
}

// FUN_001bfd60 (60 bytes)
// Code: walks up to 8 records of 16 bytes from a0. Returns the first record whose first word
//       equals a1. Otherwise stores a1 into the last record whose first word is zero (t4) and
//       returns it (t4 stays 0 if none: the store then goes to address 0, as the original).
// Build: the no-op xori is inline asm. Empty volatile asms keep gcc from filling the beq
//        slot with the movz, from copying the loop-top load into a bnezl slot, and from
//        moving "move v0,t4" into the final bnez slot.
u32* func_001bfd60(u32* a0, u32 a1) {
    register u32 z asm("$14");
    register u32* t4 asm("$12") = 0;
    register s32 i asm("$13") = 0;
    u32* r;
    do {
        asm volatile("");
        u32 v = *a0;
        asm volatile("" : "+r"(v));
        r = a0;
        asm("" : "+r"(r));
        asm("xori %0,%1,0" : "=r"(z) : "r"(v));
        if (v == a1) goto done;
        asm volatile("");
        if (z == 0) t4 = a0;
        asm("" : "+r"(t4));
        i++;
        a0 += 4;
    } while (i < 8);
    asm volatile("");
    *t4 = a1;
    r = t4;
done:
    return r;
}

// FUN_001afe30 (60 bytes)
// Code: scans three 12-byte records starting at 0x1c94094; returns the index of the first
//       whose word equals a0, or -1.
// Build: base pinned to t7 with a keep-alive use so p = b + 4 is its own addiu; the word load
//        at the loop top gives the bnezl with the load copied into its delay slot.
extern u8 D_01c90000[];
s32 func_001afe30(u32 a0) {
    register u32* p asm("$12");
    register s32 i asm("$13") = 0;
    register u8* b asm("$15") = &D_01c90000[16528];
    asm("" : "+r"(b));
    p = (u32*)(b + 4);
    asm volatile("" :: "r"(b));
    s32 r;
    do {
        u32 w = *p;
        r = i;
        i++;
        p += 3;
        if (w == a0) goto done;
    } while (i < 3);
    r = -1;
done:
    return r;
}
