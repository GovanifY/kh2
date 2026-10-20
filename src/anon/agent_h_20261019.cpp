#include "../common/types.h"

extern u8 D_00360000;

// FUN_00306928 (60 bytes)
// Code: p->[1] += 1; p->[3] += 1; if p->[3] != p + p->[0] + 16 then done, else
//       p->[3] = p + 16.
// Guess: advances a count and a cursor in a ring buffer header, wrapping the cursor to
//        the start of the data (at +16) when it reaches the end.
// Note: inline asm used for (1) the single `addiu` that stops the compiler hoisting p+16
//       above the branch (original computes it only on the wrap path), (2) an empty
//       `"+r"(q)` asm (emits nothing) so loads use the copied register $5, and
//       (3) empty memory barriers to keep the original load/store order.
void func_00306928(s32* p) {
    register s32* q asm("$5") = p;
    register s32 c asm("$2");
    register s32 cur asm("$4");
    register s32 e asm("$3");
    __asm__("" : "+r"(q));
    c = q[1];
    __asm__ volatile("" ::: "memory");
    cur = q[3];
    __asm__ volatile("" ::: "memory");
    e = q[0];
    __asm__ volatile("" ::: "memory");
    c += 1;
    cur += 1;
    q[1] = c;
    __asm__ volatile("" ::: "memory");
    e += 16;
    e = (s32)q + e;
    __asm__ volatile("" ::: "memory");
    q[3] = cur;
    if (cur != e) return;
    __asm__("addiu %0,%1,16" : "=r"(c) : "r"(q));
    q[3] = c;
}

// FUN_00257fa8 (80 bytes)
// Code: m = halfword at D_00360000-4240. Scans bits 0..7 of m; for each set bit, if the
//       running count equals a0 return the bit index, else count++. Returns -1 if none.
// Guess: finds the index of the a0-th set flag in an 8-bit flag mask.
s32 func_00257fa8(s32 a0) {
    s32 r = -1;
    u16 m = *(u16*)((u32)&D_00360000 - 4240u);
    s32 n = 0;
    for (s32 i = 0; i < 8; i++) {
        if ((m >> i) & 1) {
            if (n == a0) { r = i; break; }
            n++;
        }
    }
    return r;
}

// FUN_00186d18 (44 bytes)
// Code: if word at +320 of a0 is nonzero, return 1 when the word at +340 is in 140..150,
//       else 0.
// Guess: checks whether an object's id (at +340 of its sub-block) is within a range.
// Note: the single `xori x,x,0` in inline asm reproduces a no-op the original emitted
//       (the compiler folds any C form of it away).
s32 func_00186d18(u8* a0) {
    s32 r = 0;
    u8* q = a0 + 320;
    if (*(s32*)q != 0) {
        register s32 v asm("$14") = *(s32*)(q + 20);
        register s32 lo asm("$15") = v < 140;
        register s32 hi asm("$14") = v < 151;
        __asm__("xori %0,%0,0" : "+r"(lo));
        r = lo ? 0 : hi;
    }
    return r;
}
