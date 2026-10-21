#include "../common/types.h"

// Three small functions from the layout, all built with -falign-functions=1
// (the object's Makefile flag) because none of them sits on an 8-byte boundary.

// func_001da3f8 (36 bytes): pops 4 bytes off the downward cursor at +12 of a0
// (the cursor is decremented by 4) and copies them to a1 as an unaligned word.
// __builtin_memcpy gives the lwl/lwr loads and swl/swr stores. The asm nop
// takes the jr delay slot, which is the nop in the original.
void func_001da3f8(u8* a0, u8* a1) {
    register u8* p asm("$14");
    register u8* q asm("$15");
    p = *(u8**)(a0 + 12);
    q = p - 4;
    *(u8**)(a0 + 12) = q;
    __builtin_memcpy(a1, q, 4);
    asm volatile("nop");
}

// func_001db888 (48 bytes): decrements the index at +8, stores it back, then
// returns acc(+12) + mult(+20) * table[new index] (table pointer at +16).
s32 func_001db888(u8* a0) {
    s32 idx = *(s32*)(a0 + 8) - 1;
    *(s32*)(a0 + 8) = idx;
    s32 v = ((s32*)*(u8**)(a0 + 16))[idx];
    return *(s32*)(a0 + 12) + *(s32*)(a0 + 20) * v;
}

// func_001db8b8 (60 bytes): stores (a1 - base(+12)) / div(+20) at table[+8]
// (table pointer at +16), then increments the index at +8. The base is pinned
// to $13 (t5) so the subu operand matches the original, and the index is read
// before the divide, as in the original.
void func_001db8b8(u8* a0, u32 a1) {
    register u32 base asm("$13");
    base = *(u32*)(a0 + 12);
    s32 i = *(s32*)(a0 + 8);
    u32 q = (a1 - base) / *(u32*)(a0 + 20);
    ((u32*)*(u8**)(a0 + 16))[i] = q;
    *(s32*)(a0 + 8) = i + 1;
}
