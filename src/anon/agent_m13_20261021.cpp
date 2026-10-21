#include "../common/types.h"

// FUN_00105da8 (56 bytes). Wrapper: prepends the word at 0x33CB84 (D_0033cb84) to its four
// arguments and tail-calls func_00102818 with five arguments (a0..a3 shifted into a1..a3, t0 =
// old a3). Guess: a call that passes a context pointer as the first argument.
// Status: MATCHED (full verify, layout status cxx).
extern u32 D_0033cb84[];
extern u32 func_00102818(u32, u32, u32, u32, u32);

u32 func_00105da8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00102818(D_0033cb84[0], a0, a1, a2, a3);
}

// Not integrated (not matched):
//
// FUN_00105af8 (96 bytes): stores a0 at 0x33CAFC, B[a0-1] at 0x33CAF0 and then 0x33CAF4 gets
// B[1] for a0 == 3, B[0] for a0 == 8, else the 0x33CAF0 value (B = 0x33CB00). Best attempt has
// the first seven instructions in one volatile asm block. Remaining diff: the li/lui order and
// the store that should fill the delay slot of the first beq (49 bytes in verify).
//
// FUN_00105de0 (104 bytes): r = func_00103b38(a0); if r != 0 return r; if word 0x32B984 == 2
// return 0; else store a0 at 0x33CBAC, byte 0x33CBB0 = 1, tail-call func_00102080(0x33CB80).
// Best attempt matches everything except the order of the addiu for a0 and the ld s0 in the tail
// (8 bytes in verify). Drafts are in the scratchpad (agent_m13_full_draft.cpp).
