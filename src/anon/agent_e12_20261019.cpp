#include "../common/types.h"

typedef int u128 __attribute__((mode(TI)));

extern u8 D_00350000[];
extern u8 D_01d50000[];
extern f32 D_0034a9e0;
extern f32 D_0034a9e4;
extern u128 D_0034a9c0;
extern u128 D_0034a9d0;

// FUN_001c9db0 (72 bytes).
// Code: n = word at D_00350000 + 7984. If n <= 0, returns 0. Otherwise scans n words
//       starting at D_01d50000 - 26240 and returns 1 when one equals arg0, else 0.
// Guess: an "is this id in the active list" check over a fixed table.
u32 func_001c9db0(u32 a0) {
    register s32 n asm("$15");
    register s32 lim asm("$12");
    register u8* b asm("$15") = D_00350000;
    n = *(s32*)(b + 7984);
    s32 i = 0;
    if (n > 0) {
        lim = n;
        asm volatile("" : "+r"(lim));
        u32* p = (u32*)&D_01d50000[-26240];
        do {
            if (*p == a0) return 1;
            p++; i++;
        } while (i < lim);
    }
    return 0;
}

// FUN_0018a1b8 (96 bytes)
// Code: a0 = list header: count at +0, 20-byte entries from +64. Starting at a2+20 (or the
//       first entry when a2 is NULL), returns the first entry whose type byte (+4) has its
//       bit set in the mask a1 (1 << byte, AND with a1). Returns the entry, or 0.
// Guess: find the next record after a2 in an array of 20-byte entries whose type
//        bit is in a filter mask.
// Note: only the entry test + `move a2,t4` delay-slot placement is asm (the compiler
//       insists on filling the beqz slot from the target); the loop and everything else is C.
u8* func_0018a1b8(u8* a0, u32 a1, u8* a2) {
    u8* end = a0 + *(s32*)a0 * 20 + 64;
    register u8* s asm("$12");
    s = a0 + 64;
    u8* t = a2 + 20;
    if (a2)
        s = t;
    u32 one;
    __asm__ volatile(
        ".set noreorder\n\t"
        "sltu $15,%2,%3\n\t"
        "beqz $15,.Le12none\n\t"
        "move %0,%2\n\t"
        ".set reorder\n\t"
        "li %1,1"
        : "=r"(a2), "=r"(one) : "r"(s), "r"(end) : "$15");
    do {
        if (a1 & (one << a2[4]))
            return a2;
        a2 += 20;
    } while (a2 < end);
    __asm__ volatile(".Le12none:");
    return 0;
}

// FUN_00158b20 (84 bytes)
// Code: a0+72 = float at 0x34a9e0; a0+80 = float at 0x34a9e4. If a0+144 is not 0x34a9c0,
// copy 16 bytes from 0x34a9c0 to a0+144. Then a0 += 112, and if a0 is not 0x34a9d0, copy
// 16 bytes from 0x34a9d0 to a0.
// Guess: initialise two float fields and two 16-byte blocks of an object (a default-value copy).
void func_00158b20(u8* a0) {
    register u128* d1 asm("$13");
    register u128* s1 asm("$15");
    register u128 tmp asm("$8");
    *(f32*)(a0 + 72) = D_0034a9e0;
    d1 = (u128*)(a0 + 144);
    s1 = &D_0034a9c0;
    *(f32*)(a0 + 80) = D_0034a9e4;
    __asm__("" : "+r"(s1));
    if (d1 != s1) { tmp = *s1; __asm__ volatile("" : "+r"(d1)); *d1 = tmp; }
    a0 += 112;
    s1 = &D_0034a9d0;
    __asm__("" : "+r"(s1));
    if ((u128*)a0 != s1) { tmp = *s1; *(u128*)a0 = tmp; }
}
