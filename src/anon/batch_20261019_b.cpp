#include "../common/types.h"

// Batch 2026-10-19 B: small functions decompiled from SLPM_666.75.
// Each comment says what the code does, then gives a guess at its role.
// The guesses are unverified. They're there to help place the function later.

extern u8 D_00330000;
extern u8 D_00350000;
extern u8 D_00360000;
extern u8 D_01c60000;

// Callees that already have registry names use the existing symbol.
extern "C" u32 func_0023a918(u32) asm("_ZN2YI8SEQUENCE13GetActiveRGBAEv");
extern "C" u32 func_001b1400(u32) asm("_ZN2YS8DATABUFF5AllocEPKci");
void func_001682b8(u32, u32);
void func_00228bd8(void*);
void func_0014ace8(void);
void func_0014a988(u32);
extern "C" void func_001b0330(u32) asm("_Z16u_call4_001b0330jjjj");
extern "C" u32 func_001050d8(u32) asm("_ZN4AREA5AllocEj");
extern "C" u32 func_001b6298(u32, u32, u32, u32) asm("_Z16u_tail4_001b6298jjjj");

// FUN_002ef660 (80 bytes)
// Code: calls FUN_0023a918(first argument + 468), then stores the 32-bit result
// little-endian at the first argument and returns the first argument.
// Guess: a reader that fills a 4-byte field from a lookup keyed by an offset
// into the second argument. Probably a value-getter for a struct.
u8* func_002ef660(u8* a0, u8* a1) {
    u32 v = func_0023a918((u32)(a1 + 468));
    a0[0] = (u8)v;
    a0[1] = (u8)(v >> 8);
    a0[2] = (u8)(v >> 16);
    a0[3] = (u8)(v >> 24);
    return a0;
}

// FUN_001b1448 (72 bytes)
// Code: r = FUN_001b1400(arg). If r is non-zero, calls FUN_001682b8(arg, r).
// Returns r.
// Guess: a "look up, and if found, act on it" helper. FUN_001b1400 is the
// lookup. FUN_001682b8 is the action.
u32 func_001b1448(u32 a0) {
    u32 r = func_001b1400(a0);
    if (r != 0) {
        func_001682b8(a0, r);
    }
    return r;
}

// FUN_00228e28 (48 bytes)
// Code: calls virtual method slot 7 (offset 28) of the object at the first
// argument, passing the object. Then tail-calls FUN_00228bd8(object).
// Guess: a C++ method that calls a virtual "update" or "finish" step and then
// a shared helper. The object has a vtable at offset 0.
void func_00228e28(void* a0) {
    void (*fn)(void*) = (void (*)(void*))(((void**)(*(void**)a0))[7]);
    fn(a0);
    return func_00228bd8(a0);
}

// FUN_0014acf8 (36 bytes)
// Code: calls FUN_0014ace8(). Then tail-calls FUN_0014a988 with the constant
// address 0x003493a0.
// Guess: a setup step followed by a call with a fixed data address.
void func_0014acf8(void) {
    func_0014ace8();
    return func_0014a988((u32)&D_00350000 + (s32)-27744);
}

// FUN_00135cc8 (52 bytes)
// Code: reads a count from +12 of the first argument. For each of the next
// count words (starting at +16), if the word equals the second argument, it
// stores the third argument in its place and returns.
// Guess: a search-and-replace over a small array of IDs. The array starts at
// +16 and the count is at +12.
void func_00135cc8(u8* a0, u32 a1, u32 a2) {
    s32 n = *(s32*)(a0 + 12);
    for (s32 i = 0; i < n; i++, a0 += 4) {
        if (*(u32*)(a0 + 16) == a1) {
            *(u32*)(a0 + 16) = a2;
            return;
        }
    }
}

// FUN_001b6c60 (72 bytes)
// Code: calls FUN_001b0330(word at +2488 of the argument). Clears the byte at
// 0x0032f054. Calls FUN_001050d8(32) and tail-calls FUN_001b6298(result,
// argument, 0, 0).
// Guess: an allocation followed by a setup call. The byte at 0x0032f054 looks
// like a flag that's cleared at this point.
u32 func_001b6c60(u32 a0) {
    func_001b0330(*(u32*)(a0 + 2488u));
    *(u8*)((u32)&D_00330000 - 4012u) = 0;
    u32 v = func_001050d8(32u);
    return func_001b6298(v, a0, 0u, 0u);
}

// FUN_00196300 (40 bytes)
// Code: calls FUN_001b1448(word at 0x00350334) and stores the result at
// 0x01c61b04.
// Guess: caches the result of a lookup on a global value into a fixed global
// slot.
void func_00196300(void) {
    u32 r = func_001b1448(*(u32*)((u32)&D_00350000 + 820u));
    *(u32*)((u32)&D_01c60000 + 6916u) = r;
}
