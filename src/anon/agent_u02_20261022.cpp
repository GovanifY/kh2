#include "../common/types.h"

// Agent U02 (2026-10-22): two functions from SLPM_666.75 (FUN_001542c8, FUN_001548a8).
// Each comment says what the code does, then gives a guess at its role.
// FUN_00154ee8 is not matched and is not included here (see the report).

// Callees.
extern "C" u32 func_001541d8(u32, u32, u32);   // C++ method FACE::getFaceSed(void**, OBJ*) (this, out, obj).
extern "C" u32 func_00154288(u32);
extern "C" void func_001387f8(u32, u32, u32, u32);
extern "C" void func_001395a8(u32);            // C++ method Obj2D::localShow(this).

// C linkage for the two functions below (the registry keys are func_<addr>).
extern "C" void func_001542c8(u32, u32, u32);
extern "C" void func_001548a8(u8*, s32);

// FUN_001542c8 (104 bytes).
// Code: a local word is zeroed, then func_001541d8(a0, &local, a1) is called. The original a2 is kept
// in s0 across the call and moved into a1 after it (dead on both paths, but the move stays in the output).
// If the result is 1, func_00154288(a0) is called, then func_001387f8(a0, local, a0 + 416, that result).
// Guess: a lookup that fills a local word, then a follow-up on a sub-object at +416 when the lookup returns 1.
// Matching: the post-call move to $5 is an empty-output asm with "r" input so it stays in the original order.
void func_001542c8(u32 a0, u32 a1, u32 a2) {
    u32 tmp = 0;
    register u32 r5 asm("$5");
    u32 r = func_001541d8(a0, (u32)&tmp, a1);
    asm volatile("move %0,%1" : "=r"(r5) : "r"(a2));
    if (r == 1) {
        u32 v = func_00154288(a0);
        func_001387f8(a0, tmp, a0 + 416, v);
    }
}

// FUN_001548a8 (100 bytes).
// Code: if the word at +15568 is non-zero and n > 0, loops n times over records at +2904 with a stride of 816.
// For the first 16 iterations (counter i < 16) it calls func_001395a8(record) (Obj2D::localShow).
// Guess: a loop that shows up to 16 entries of a list of 816-byte entries.
// Matching: the counter is pinned to $17 (s1) and the record pointer to $16 (s0). The counter is set in
// the blez delay slot, and the pointer is formed after the zero store, which fixes the order.
// Needs -falign-functions=1 for this object (100 bytes is not a multiple of 8).
void func_001548a8(u8* a0, s32 a1) {
    if (*(u32*)(a0 + 15568) != 0 && a1 > 0) {
        register s32 i asm("$17") = 0;
        register u8* p asm("$16");
        i = 0;
        asm volatile("" : "+r"(i));
        p = a0 + 2904;
        do {
            if (i < 16) func_001395a8((u32)p);
            i++;
            p += 816;
        } while (i < a1);
    }
}
