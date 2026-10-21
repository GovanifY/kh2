#include "../common/types.h"

// Callees. extern "C" so each name is the plain func_<addr> symbol, as in agent_m12_20261021.cpp.
extern "C" u32 func_00102c18(u32 a0, u32 a1, u32 a2);
extern "C" void func_002ba848(u32 a0);
extern "C" u32 func_00136a18(void);

// Data. D_00137250 is an address in read-only data (passed as a pointer argument).
// D_00347d54, D_00347d55 and D_00347d56 are separate bytes. The original loads each one through
// its own lui, so they are declared as separate symbols instead of offsets from one base.
extern u8 D_00137250;
extern u8 D_00347d54;
extern u8 D_00347d55;
extern u8 D_00347d56;

// FUN_00136fa8 (40 bytes)
// Code: tail-calls FUN_00102c18(1, 300000, 0x00137250). The frame is saved and restored around
//       the tail jump (sd/ld of ra), which gcc emits by itself for this shape.
// Guess: starts a call with a fixed count (300000) and a constant string or table pointer.
// Note: the constant is taken through the symbol, so gcc emits lui/addiu (signed low half).
//       An integer constant gives lui/ori instead, which does not match.
u32 func_00136fa8(void) {
    return func_00102c18(1, 300000, (u32)&D_00137250);
}

// FUN_001373a0 (56 bytes)
// Code: byte at 0x00347d55 = 0; t = byte at 0x00347d54; byte at 0x00347d56 = t;
//       byte at 0x00347d54 = 0 (in the jal delay slot); calls FUN_002ba848(960);
//       then tail-calls FUN_00136a18().
// Guess: consumes a one-byte pending flag (0x347d54) into a second flag (0x347d56) and clears a third.
// Note: the real call makes gcc keep the frame on its own. The store to 0x347d54 stays before the
//       call, which is the order gcc gives for this shape.
u32 func_001373a0(void) {
    D_00347d55 = 0;
    u8 t = D_00347d54;
    D_00347d56 = t;
    D_00347d54 = 0;
    func_002ba848(960);
    return func_00136a18();
}

// FUN_00136ab8 (68 bytes): NOT matched. Not defined here, so the layout keeps the original asm.
// Code: zeroes 8 words at 0x00347d30..0x00347d4f, then tail-calls FUN_00136a98 (already matched in
//       agent_f15_20261019.cpp). The word at 0x00347d40 is its own symbol (lui/sw), and the
//       other 7 words go through a base pointer (p) with q = p + 4.
// Best attempt so far, which still differs from the original in 8 instruction words:
//   D_00347d30 = 0;  BAR();  p = &D_00347d30 (pinned $14);  q = p + 4 (pinned $13);
//   q[2]=0; D_00347d40=0; p[1]=0; p[7]=0; p[3]=0; p[2]=0; q[1]=0; func_00136a98();
//   with empty "memory" asm barriers between stores and -falign-functions=1 for the trailing pad.
//   Remaining diffs: the first store lui uses $14 instead of $15, and sd ra lands before addiu $13.
