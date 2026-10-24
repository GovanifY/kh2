#include "../common/types.h"

// FUN_00170530 (60 bytes)
// Code: saves a2, calls wtarget_00170400(a0, a1, a3, a3), then stores the saved a2 as a halfword at +56,
// halfword -1 at +58 and byte 1 at +0 of the returned pointer.
// Guess: initialises a small record returned by the allocator-style callee.
u32 wtarget_00170400(u32, u32, u32, u32);

void func_00170530(u32 a0, u32 a1, u32 a2, u32 a3) {
    register u32 neg asm("$15");
    register u32 one asm("$14");
    u8* v = (u8*)wtarget_00170400(a0, a1, a3, a3);
    *(u16*)(v + 56) = (u16)a2;
    asm volatile("" ::: "memory");
    neg = 0xffffffffu;
    asm volatile("" : "+r"(neg));
    one = 1;
    asm volatile("" : "+r"(one));
    *(u16*)(v + 58) = (u16)neg;
    asm volatile("" ::: "memory");
    v[0] = (u8)one;
}
