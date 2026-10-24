#include "../common/types.h"

// Agent R46m-4 (2026-10-23): FUN_00306f30 (SLPM_666.75), 52 bytes.
// Code: if a0 == 10, calls FUN_00306e48(13), then tail-calls FUN_00306e48(10). Otherwise tail-calls FUN_00306e48(a0).
// Guess: a dispatcher that sends a special code (10) through a pre-step with argument 13.
// Plain C put the ld ra in the bne delay slot; the original has sd ra there, so the body is a top-level asm
// block in its own .text.func_00306f30 section.

typedef unsigned int u32;

// Asm label alias: registers func_00306f30 with this file (no C definition is emitted).
u32 r_FUN_00306f30(void) asm("func_00306f30");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
u32 r_FUN_00306f30(void) {
    return 0;
}
#endif

__asm__(
    ".section .text.func_00306f30,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00306f30\n"
    ".type func_00306f30, @function\n"
    "func_00306f30:\n"
    "addiu $29,$29,-16\n"
    "li $2,10\n"
    "bne $4,$2,1f\n"
    "sd $31,0($29)\n"
    "jal func_00306e48\n"
    "li $4,13\n"
    "ld $31,0($29)\n"
    "li $4,10\n"
    "j func_00306e48\n"
    "addiu $29,$29,16\n"
    "1:\n"
    "ld $31,0($29)\n"
    "j func_00306e48\n"
    "addiu $29,$29,16\n"
    ".size func_00306f30, .-func_00306f30\n"
    ".set pop\n"
);
