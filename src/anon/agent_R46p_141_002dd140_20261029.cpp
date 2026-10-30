#include "../common/types.h"

// Agent R46p_141 (2026-10-29): FUN_002dd140 (84 bytes), SLPM_666.75.
// Same bytes as FUN_002d2070 (checked: identical 84-byte body). Copies the 10-byte block at
// 0x32BAE0 to a stack local, calls FUN_00195750(a0) (the first call is inline asm so its
// delay slot is a nop), then calls FUN_00104f58(&local, 1, 0, 0, 0).
// FUN_00195750 has a func_ row; FUN_00104f58 does not, so it is called by numeric jal.
extern "C" void call_00104f58(void*, s32, s32, s32, s32) asm("0x104f58");
extern u8 D_00330000[];
struct Blob10 { u8 d[8]; u16 b; } __attribute__((aligned(2)));

void func_002dd140(void* a0) {
    Blob10 t = *(Blob10*)(D_00330000 - 17696);
    register void* r4 asm("$4") = a0;
    __asm__ volatile(".set noreorder\n\tjal func_00195750\n\tnop\n\t.set reorder"
        : : "r"(r4) : "$31", "memory");
    call_00104f58(&t, 1, 0, 0, 0);
}
