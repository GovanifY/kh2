#include "../common/types.h"

// Agent R4: three leaf functions in the 0x001b8xxx area, each byte-matched.
//
// Data notes:
//   0x3511b8, 0x3511bc, 0x3511c2 are a word, a word and a byte in one block (0x350000 + offsets).
//   0x1d48cb8 is a word; the array base is 16 bytes above it (0x1d48cc8), with a count word at
//   base+192 and entries at base+160+4*n.

// Literal high halves and small constants are written as asm into pinned registers. That makes
// stores take their low half as an immediate, which is how the original code is laid out.
#define LUI(reg, hi) __asm__ volatile("lui %0," #hi : "=r"(reg) : : "memory")

extern u8 D_01d48cb8;

// FUN_001b8228 (48 bytes)
// x = 0x003a99f0 (the address of D_003a99f0, built as lui/addiu), y = x + 0x4000.
// Stores x at 0x1d48cb8, y at 0x3511bc, x at 0x3511b8, and zero to the byte at 0x3511c2.
// Guess: resets a pair of pointer-sized globals in a init step.
void func_001b8228(void) {
    register u32 x asm("$13");
    register u32 y asm("$12");
    register u8* p0 asm("$14");
    register u8* p1 asm("$15");
    __asm__ volatile("lui %0,0x3b" : "=r"(x) : : "memory");
    LUI(p1, 0x35);
    __asm__ volatile("addiu %0,%0,-26128" : "+r"(x) : : "memory");
    LUI(p0, 0x1d5);
    __asm__ volatile("addiu %0,%1,16384" : "=r"(y) : "r"(x) : "memory");
    *(u32*)(p0 - 29512) = x;
    *(u32*)(p1 + 4540) = y;
    LUI(p0, 0x35);
    LUI(p1, 0x35);
    *(u32*)(p0 + 4536) = x;
    *(u8*)(p1 + 4546) = 0;
}

// FUN_001b8258 (52 bytes)
// Stores 0x70004000 at 0x3511bc, 1 at 0x3511c2, 0x70000000 at 0x3511b8, and 0x70000000 at
// 0x1d48cb8 (the last store is in the jr delay slot).
// Guess: sets the same pair of globals to a fixed "enabled" state.
void func_001b8258(void) {
    register u32 a asm("$13");
    register u32 one asm("$12");
    register u32 b asm("$11");
    register u8* p6 asm("$14");
    register u8* p7 asm("$15");
    LUI(a, 0x7000);
    LUI(p7, 0x35);
    LUI(p6, 0x35);
    __asm__ volatile("ori %0,%0,0x4000" : "+r"(a) : : "memory");
    __asm__ volatile("li %0,1" : "=r"(one) : : "memory");
    *(u32*)(p6 + 4540) = a;
    *(u8*)(p7 + 4546) = (u8)one;
    LUI(b, 0x7000);
    LUI(p6, 0x35);
    LUI(p7, 0x1d5);
    *(u32*)(p6 + 4536) = b;
    *(u32*)(p7 - 29512) = b;
}

// FUN_001b86e0 (56 bytes)
// key = ((a0 - base) >> 2) * 0xCCCCCCCD (low word), with base = 0x1d48cc8.
// n = count word at base+192; the count is bumped to n+1; key is stored at base+160+4*n.
// Guess: appends an entry to a small table. The key is a scaled index (divide by 5 via the
// 0xCCCCCCCD reciprocal).
void func_001b86e0(u32 a0) {
    register u32* base asm("$12");
    register s32 mul asm("$13");
    register u32 n asm("$15");
    register u32 off asm("$14");
    u32* ent;
    s32 d;
    s32 key;
    u32 np;
    base = (u32*)((u32)&D_01d48cb8 + 16u);
    mul = (s32)0xCCCCCCCDu;
    d = (s32)(a0 - (u32)base);
    __asm__ volatile("" : "+r"(d) : : "memory");
    n = base[48];
    __asm__ volatile("" : "+r"(n), "+r"(d) : : "memory");
    d = d >> 2;
    key = d * mul;
    __asm__ volatile("" : "+r"(key) : : "memory");
    off = n * 4;
    np = n + 1;
    __asm__ volatile("" : "+r"(off), "+r"(np) : : "memory");
    ent = (u32*)((u8*)base + off);
    __asm__ volatile("" : "+r"(ent) : : "memory");
    base[48] = np;
    __asm__ volatile("" : : : "memory");
    ent[40] = (u32)key;
}
