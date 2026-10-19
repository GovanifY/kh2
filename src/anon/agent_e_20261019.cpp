#include "../common/types.h"

extern u8 D_003617D8;
extern u8 D_003617DC;
extern u8 D_00340000;

// FUN_002bd230 (32 bytes)
// Code:
//   v0 = word at 0x003617d8                  ; old value
//   word at 0x003617d8 = a0
//   barrier (no code): keeps the store before the compare
//   v0 = (old == a0)
//   word at 0x003617dc = a1                  ; store in jr delay slot
//   return v0
// Guess: swaps a pair of 32-bit state words and reports whether the previous
//   first word equaled the new one (a change-detect / cached-key check).
s32 func_002bd230(u32 a0, u32 a1) {
    u32 old = *(u32*)&D_003617D8;
    *(u32*)&D_003617D8 = a0;
    __asm__ volatile("" ::: "memory");
    s32 r = old == a0;
    __asm__ volatile("" ::: "memory");
    *(u32*)&D_003617DC = a1;
    return r;
}

// FUN_0010a7d8 (36 bytes)
// Code:
//   byte at 0x00340ed0 = a0 & 0xff
//   byte at 0x00340ed2 = a2 & 0xff          ; before jr
//   byte at 0x00340ed1 = a1 & 0xff          ; in jr delay slot
// Guess: stores three byte-sized settings into a small config block at
//   0x00340ed0..0x00340ed2.
void func_0010a7d8(u8 a0, u8 a1, u8 a2) {
    u8* p = (u8*)((u32)&D_00340000 + 3792u);
    p[0] = a0;
    p[1] = a1;
    p[2] = a2;
}

// FUN_003060f0 (16 bytes)
// Code:
//   v0 = COP0 Status register (mfc0 $12)
//   v0 = (v0 ^ 1) & 1
//   return v0
// Guess: returns the inverse of the Status register's bit 0 (IE-style
//   flag), used as a boolean interrupt-state query.
s32 func_003060f0(void) {
    u32 v;
    __asm__ volatile("mfc0 %0, $12" : "=r"(v));
    return (s32)((v ^ 1u) & 1u);
}
