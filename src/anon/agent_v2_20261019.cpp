#include "../common/types.h"

// Address of the global pointer at 0x01d49358. Declared as an extern so gcc emits
// R_MIPS_HI16/LO16 against the symbol; the link produces the original lui 0x1d5 / -27816 pair.
extern u8* D_01d49358;

// FUN_001c0268 (44 bytes)
// Code: n = word at a1+28. Takes the u32 word at a0 + (n >> 5) * 4 + 4 and tests bit (n & 31).
// Returns 1 if that bit is clear, else 0.
// Guess: bitmap lookup, "is entry n unset" over an array of u32 words.
// Notes: plain C. The mask is 1 << (n & 31) (sllv) and the result is (x < 1u) (sltiu in the delay slot).
s32 func_001c0268(u8* a0, u8* a1) {
    u32 n = *(u32*)(a1 + 28);
    u32* p = (u32*)(a0 + ((n >> 5) << 2));
    u32 one = 1;
    u32 m = one << (n & 31);
    return (p[1] & m) < 1u;
}

// FUN_001c0410 (68 bytes)
// Code: a loop over four 8-byte slots starting at a0 + 48. The first slot whose word is zero
// receives the word at a1+28, and a float (u16 at a2+38 converted to f32) is stored at +52
// of that slot. Returns void. If no slot is free, it returns with nothing stored.
// Guess: claim a free entry in a small table and fill it from two sources.
// Notes:
//  - i is pinned to t6 ($14). The halfword temp is pinned to t6 as well, since i is dead on the store path.
//  - asm volatile("" : "+r"(w)) keeps the load ahead of the increment, so the increment
//    lands in the delay slot of the bnez (not bnezl).
//  - The do/while makes the compare the latch block, which gives the alignment nop before it.
//  - Needs -falign-functions=1 for its object (68 bytes is not a multiple of 8).
void func_001c0410(u8* a0, u8* a1, u8* a2) {
    register s32 i asm("$14");
    register u32 h asm("$14");
    i = 0;
    do {
        u32 w = *(u32*)(a0 + 48);
        asm volatile("" : "+r"(w));
        i++;
        if (w == 0) {
            *(u32*)(a0 + 48) = *(u32*)(a1 + 28);
            asm volatile("" ::: "memory");
            h = *(u16*)(a2 + 38);
            *(f32*)(a0 + 52) = (f32)(s32)h;
            return;
        }
        asm volatile("" ::: "memory");
        a0 += 8;
    } while (i < 4);
}

// FUN_001c0648 (68 bytes)
// Code: loads the pointer stored at the global D_01d49358 and reads the count n at +4 of that block.
// Scans 16-byte records starting at +8 for a record whose first byte equals a0. Returns a pointer to
// the first match, else NULL.
// Guess: find a record by its one-byte id in a table whose header holds the count.
void* func_001c0648(s32 a0) {
    u8* p = D_01d49358;
    s32 n = *(s32*)(p + 4);
    s32 i = 0;
    p += 8;
    if (n > 0) {
        do {
            if (*(u8*)p == a0) return p;
            p += 16;
            i++;
        } while (i < n);
    }
    return 0;
}
