#include "../common/types.h"

// FUN_001d2110 (32 bytes, leaf)
// Code: loads the word at +24 of a0 (call it hi). Clamps a1 to the range 0..hi: if a1 <= 0
// the value becomes 0, and if a1 >= hi it becomes hi. The result is stored at +44 of a0.
// The two compares are computed before the moves, and the moves are movz on a1 (the
// original reuses a1 as the destination). The "xori t7,t7,0" in the original is a no-op;
// it is kept as an empty asm on t7 so gcc emits the same instruction.
// Guess: clamps a value to a per-object maximum read from the object.
void func_001d2110(u8* a0, s32 a1) {
    s32 hi = *(s32*)(a0 + 24);
    s32 t6 = 0 < a1;
    s32 t7 = a1 < hi;
    __asm__("xori %0,%0,0" : "+r"(t7));
    if (t6 == 0) a1 = 0;
    if (t7 == 0) a1 = hi;
    *(s32*)(a0 + 44) = a1;
}

// FUN_001da3d8 (32 bytes, leaf)
// Code: loads the destination pointer at +12 of a0 into t7. Copies one unaligned 32-bit word
// from a1 to that pointer with lwl/lwr then swl/swr (data register t3), then advances the
// pointer by 4 and stores it back at +12 of a0. The loads and stores are one asm block so the
// partial moves keep their original order and register; the pointer update stays in C.
// Guess: appends one unaligned word to a byte stream held in a writer object.
void func_001da3d8(u8* a0, u8* a1) {
    u8* d = *(u8**)(a0 + 12);
    register u32 w asm("$11");
    __asm__ volatile(
        "lwl %0,3(%1)\n\t"
        "lwr %0,0(%1)\n\t"
        "swl %0,3(%2)\n\t"
        "swr %0,0(%2)\n\t"
        : "+r"(w)
        : "r"(a1), "r"(d)
        : "memory");
    *(u8**)(a0 + 12) = d + 4;
}

// FUN_001efc28 (32 bytes, leaf)
// Code: reads the pointer at +12 of a1, then the word at +4 of that record. Adds it to a0 to
// get a base address. Clears three words at base+160, +164 and +168. The first store uses a0
// as its base, and t7 = base+160 serves the other two stores. Empty asm barriers keep the
// two bases in separate registers, and volatile stores keep the ascending order.
// Guess: resets a three-word block at a fixed offset inside an object selected by a table entry.
void func_001efc28(u8* a0, u8* a1) {
    u8* t = *(u8**)(a1 + 12);
    s32 off = *(s32*)(t + 4);
    u8* b = a0 + off;
    u8* p = b + 160;
    __asm__("" : "+r"(p));
    __asm__("" : "+r"(b));
    *(volatile u32*)(b + 160) = 0;
    *(volatile u32*)(p + 4) = 0;
    *(volatile u32*)(p + 8) = 0;
}
