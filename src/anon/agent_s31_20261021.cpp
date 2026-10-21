#include "../common/types.h"

// Globals used below. Each address is the one the original code computes with lui/addiu or
// lui/ld/lw pairs (the offsets are from the 0x00370000 and 0x00350000 bases).
extern u64 D_0036b0d8;  // 0x00370000 - 20264: 64-bit global copied into the object at +272 / +304
extern u64 D_0036b0e0;  // 0x00370000 - 20256: same role as D_0036b0d8, used by FUN_0014ba90
extern u8 D_00349da8[]; // 0x00350000 - 25176: address stored as a word at +0 of the object
extern s32 D_00349e04;  // 0x00350000 - 25084: counter, incremented once per call of FUN_0014cf18
extern s32 D_00349e08;  // 0x00350000 - 25080: counter, incremented once per call of FUN_0014cf18

// Callees. Each has an asm body at the given address. They are declared extern "C" when a
// func_ registry line exists for them, and as plain C++ otherwise.
u32 func_0014b290(u32);
extern "C" void func_0014ccb8(void);
extern "C" void func_0014ca48(void);
extern "C" void func_0014d4e8(void);
extern "C" void func_003058d0(u32);

// FUN_0014cf18 (104 bytes). MATCH candidate.
// Code: calls FUN_0014ccb8(), FUN_0014ca48(); increments the word counter at 0x00349e04 and
//   the word counter at 0x00349e08 (load, add 1, store); calls FUN_0014d4e8(); calls
//   iFlushCache(0) and iFlushCache(2); then `sync` and `ei`; returns 0.
// Matching notes: the two counters use asm("nop") as a delay-slot blocker. Without it gcc
//   moves the second store into the delay slot of jal FUN_0014d4e8, while the original has a
//   real nop there. The counter pointers are plain globals. The `sync` and `ei` come from
//   inline asm (ei is emitted as .word-compatible `ei` on the EE assembler).
extern "C" int func_0014cf18(void);
int func_0014cf18(void) {
    func_0014ccb8();
    func_0014ca48();
    volatile s32* q1 = &D_00349e04;
    volatile s32* q2 = &D_00349e08;
    *q1 = *q1 + 1;
    *q2 = *q2 + 1;
    __asm__ volatile("nop" ::: "memory");
    func_0014d4e8();
    func_003058d0(0);
    func_003058d0(2);
    __asm__ volatile("sync");
    __asm__ volatile("ei");
    return 0;
}

// FUN_0014ba20 (108 bytes). NOT MATCHED, not registered.
// Code: calls FUN_0014b290(a0), then stores into the object at a0 nine values: two 64-bit
//   constants (1<<60 | 0x8001 and 14, 64), a 64-bit global (D_0036b0d8), and the address
//   D_00349da8 as a word at +0.
// Remaining diff: the scheduler puts `ld ra` and the constant setup in a different order than
//   the original (the original loads ra right after lui 0x37). Pins and barriers changed one
//   place at a time, but each fix broke another. Body is 27 instructions when compiled.
// Needs -falign-functions=1 if it is ever registered (108 bytes is not a multiple of 8).
