#include "../common/types.h"

extern u32 D_00330000[];

// FUN_00100338 (20 bytes)
// Code: opens a 16-byte frame, saves and reloads ra (sd/ld at 0(sp)), pops the
// frame and returns. No other work.
// Guess: an empty hook or stub left over from a removed call site. Same shape as
// func_00101d38, so it uses the same empty asm that clobbers $31.
void func_00100338(void) {
    __asm__ volatile("" ::: "$31");
    __builtin_return_address(0);
}

// FUN_001003b0 (20 bytes)
// Code: identical to FUN_00100338 (16-byte frame, sd/ld ra, jr ra).
// Guess: another empty stub, a sibling of func_00100338.
void func_001003b0(void) {
    __asm__ volatile("" ::: "$31");
    __builtin_return_address(0);
}

// FUN_001041c0 (32 bytes)
// Code: v = word at 0x32ba84 (&D_00330000[-4447]). If v is zero, store 1 there
// and return 1. Otherwise return v unchanged.
// Guess: a one-shot init flag. The first caller gets 1 and sets the flag; later
// callers get the old nonzero value back.
// Matching notes: the original loads the word, branches on it, and puts
// "li t7,1" in the bnez delay slot. It then sets v0 to 1 before the store, so
// the store uses t7. Pinning the base to $14 (t6) and the constant to $15 (t7)
// keeps the order. The "li t7,1" is a one-instruction asm that depends on the
// loaded value, so the scheduler can't hoist it above the load. The "+r" memory
// barrier on v keeps the v0 write ahead of the store.
u32 func_001041c0(void) {
    register u32* base asm("$14");
    register u32 one asm("$15");
    register u32 v asm("$2");
    base = &D_00330000[-4447];
    v = *base;
    __asm__ volatile("li %0,1" : "=r"(one) : "r"(v));
    if (v == 0) {
        v = 1;
        __asm__ volatile("" : "+r"(v) :: "memory");
        *base = one;
    }
    return v;
}
