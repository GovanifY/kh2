#include "../common/types.h"

// Batch 2026-10-19 A: small functions decompiled from SLPM_666.75.
// Each comment says what the code does, then gives a guess at its role.
// The guesses are unverified. They're there to help place the function later.

extern u8 D_00360000;

// Callees that already have registry names use the existing symbol.
extern "C" void func_00292630(u32) asm("_ZN2Tz18LoadDataIsFlushingEv");
void func_0029e430(void);
extern "C" void func_00293c40(u32, u32) asm("_ZN2Tz6JMData14LoadObjRequestEib");
extern "C" void func_002925c0(void) asm("_ZN2Tz13LoadDataFlushEv");
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
