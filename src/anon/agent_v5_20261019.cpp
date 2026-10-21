#include "../common/types.h"

extern u8 D_00350000[];
extern u8 D_00370000[];

// FUN_001cfac0 (48 bytes): scales the four float args (f12..f15) by the float at
// D_00370000 - 7328 and stores them at a0+2960, +2964, +2968, +2972.
// The barriers keep the four multiplies in source order and the four stores in
// source order (GCC otherwise swaps the f14/f15 multiplies and the f15 store).
void func_001cfac0(u8* a0, f32 x, f32 y, f32 z, f32 w) {
    u8* kp = &D_00370000[-7328];
    __asm__("" : "+r"(kp));  // keep the addiu separate so the lwc1 offset stays 0
    f32 k = *(f32*)kp;
    f32 p0 = x * k;
    __asm__ volatile("" : "+f"(p0));
    f32 p1 = y * k;
    __asm__ volatile("" : "+f"(p1));
    f32 p2 = z * k;
    __asm__ volatile("" : "+f"(p2));
    f32 p3 = w * k;
    __asm__ volatile("" : "+f"(p3));
    *(f32*)(a0 + 2960) = p0;
    __asm__ volatile("" ::: "memory");
    *(f32*)(a0 + 2964) = p1;
    __asm__ volatile("" ::: "memory");
    *(f32*)(a0 + 2968) = p2;
    __asm__ volatile("" ::: "memory");
    *(f32*)(a0 + 2972) = p3;
}

// FUN_001d3498 (52 bytes): a0 is a header whose word at +4 is a count of 96-byte
// records starting at a0+8. a1 == 0 returns the first record. Otherwise it returns
// a1+96, except that when a1 is the last record the result is 0 (movn on a1 != last).
u32 func_001d3498(u8* a0, u8* a1) {
    if (a1 == 0)
        return (u32)(a0 + 8);
    s32 n = *(s32*)(a0 + 4);
    u8* last = a0 + n * 96 - 88;
    return (a1 != last) ? (u32)(a1 + 96) : 0;
}

// FUN_001d3000 (92 bytes): piecewise-linear remap of x through the 4-float record at
// the pointer stored in the global at D_00350000 + 8496. Returns D (+240) when x >= A
// (+248), C (+244) when x <= B (+252), else C + (D-C)*(x-B)/(A-B).
// A and B are pinned to $f0 and $f1 so the branch-likely delay slots match the original.
f32 func_001d3000(f32 x) {
    f32* p = *(f32**)&D_00350000[8496];
    register f32 A asm("$f0") = p[62];
    if (A <= x)
        return p[60];
    register f32 B asm("$f1") = p[63];
    if (x <= B)
        return p[61];
    f32 D = p[60];
    f32 C = p[61];
    x = x - B;
    A = A - B;
    return C + (D - C) * (x / A);
}
