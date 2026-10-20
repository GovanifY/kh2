#include "../common/types.h"

// Agent S (2026-10-19): retries of previously unmatched functions.

extern u8 D_00360000;

u32 func_0014aba8(void);
void func_0014aa58(u32, u32, u32);
void func_00287cc0(u32);
void func_0028da70(u32, u32);
void func_00139d78(u32);

// FUN_0025ccc0 (48 bytes)
// Code: r = FUN_0014aba8(); FUN_0014aa58(r, 15, 0); then tail-calls FUN_00287cc0(0).
// Guess: a "begin effect/sound 15, then release" helper.
void func_0025ccc0(void) {
    u32 r = func_0014aba8();
    func_0014aa58(r, 15, 0);
    func_00287cc0(0);
}

// FUN_002803e0 (60 bytes)
// Code: reads the pointer at 0x35f264 and calls FUN_0028da70(ptr + 24, 8); rereads the
// pointer and tail-calls FUN_0028da70(ptr + 460, 11).
// Guess: two sub-object updates of one global object with type codes 8 and 11.
void func_002803e0(void) {
    func_0028da70(*(u32*)((u32)&D_00360000 - 3484u) + 24u, 8);
    func_0028da70(*(u32*)((u32)&D_00360000 - 3484u) + 460u, 11);
}

// FUN_00262730 (56 bytes)
// Code: p = FUN_00257770() + 2504; FUN_00139d78(p); then tail-calls FUN_0028da70(p, 242).
// Guess: set up and then register a sub-object (at +2504) of the object FUN_00257770 returns.
// The original keeps a nop in the delay slot of the first jal (the assembler would
// otherwise move "sd s0,0(sp)" there), so that call is written as a noreorder asm block.
void func_00262730(void) {
    register u32 v asm("$2");
    asm volatile(".set noreorder\n\tjal func_00257770\n\tnop\n\t.set reorder"
                 : "=r"(v)
                 : /* no inputs */
                 : "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15",
                   "$24", "$25", "$31", "memory");
    u32 p = v + 2504u;
    func_00139d78(p);
    func_0028da70(p, 242);
}
