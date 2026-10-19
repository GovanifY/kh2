#include "../common/types.h"

// Batch 2026-10-19 A: small functions decompiled from SLPM_666.75.
// Each comment says what the code does, then gives a guess at its role.
// The guesses are unverified. They're there to help place the function later.

extern u8 D_00360000;

void func_00292630(u32);
void func_0029e430(void);
void func_00293c40(u32, u32);
void func_002925c0(void);
void func_0018a008(u32, u32);
u32 func_002b6708(u32, u32, u32);

// FUN_001b7ff8 (20 bytes)
// Code: returns the word at +8 of the first argument, then stores it back
// advanced by (second argument << 4).
// Guess: a bump cursor. Each call reserves a1 records of 16 bytes and returns
// the old cursor.
u32 func_001b7ff8(u32 a0, u32 a1) {
    u32 old = *(u32*)(a0 + 8u);
    *(u32*)(a0 + 8u) = old + (a1 << 4);
    return old;
}

// FUN_00147c78 (36 bytes)
// Code: copies the 4 bytes at offsets 232..235 of the second argument to
// offsets 12..15.
// Guess: moves a 4-byte field inside a larger struct. The struct layout is
// not known yet.
void func_00147c78(u32 a0, u8* a1) {
    a1[12] = a1[232];
    a1[15] = a1[235];
    a1[13] = a1[233];
    a1[14] = a1[234];
}

// FUN_002ef180 (56 bytes)
// Code: if the word at +12 of the first argument is non-zero, tail-calls
// FUN_0018a008 with that word and the constant 0x002ef1b8. Otherwise returns.
// Guess: a "release if set" helper. 0x002ef1b8 is probably a string or data
// pointer, and that's worth checking.
void func_002ef180(u32* a0) {
    if (a0[3] != 0) {
        return func_0018a008(a0[3], 0x002ef1b8u);
    }
}

// FUN_002b7efc (64 bytes)
// Code: calls FUN_002b6708(2, 47, first argument) and returns its result.
// Guess: a wrapper that fixes the first two arguments (2 and 47) of
// FUN_002b6708. Those look like a type and an ID.
u32 func_002b7efc(u32 a0) {
    return func_002b6708(2, 47, a0);
}

// FUN_0029e3e0 (80 bytes)
// Code: calls FUN_00292630(first argument), then FUN_0029e430(). It then:
//   - reads the signed byte at 0x35f228 and passes (byte == 1) as the second
//     argument of FUN_00293c40
//   - stores the low 16 bits of the first argument at 0x35f5b6
//   - calls FUN_00293c40 with the sign-extended low 16 bits as the first
//     argument
//   - tail-calls FUN_002925c0
// Guess: a state update. The byte at 0x35f228 looks like a flag, and 0x35f5b6
// looks like the stored value.
void func_0029e3e0(s32 a0) {
    func_00292630(a0);
    func_0029e430();
    s8 flag = *(s8*)((u32)&D_00360000 - 3544u);
    *(s16*)((u32)&D_00360000 - 2634u) = (s16)a0;
    func_00293c40((u32)(s32)(s16)a0, (u32)(flag == 1));
    return func_002925c0();
}
