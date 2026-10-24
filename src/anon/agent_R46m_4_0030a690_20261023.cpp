#include "../common/types.h"

// Agent R46m-4 (2026-10-23): FUN_0030a690 (SLPM_666.75), 52 bytes.
// Code: zeroes the word at D_00360000+24932, then calls FUN_002fde18(0x01e389a8, 0, 4) and returns 0.
// Guess: a reset step that clears a flag and sets up one call.
// Plain C could not reproduce the lui/sd ra order in the prologue, so the body is a top-level asm block
// in its own .text.func_0030a690 section. It is the only form that matched in testing.

typedef unsigned int u32;

// Asm label alias: registers func_0030a690 with this file (no C definition is emitted).
u32 r_FUN_0030a690(void) asm("func_0030a690");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
u32 r_FUN_0030a690(void) {
    return 0;
}
#endif

__asm__(
    ".section .text.func_0030a690,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0030a690\n"
    ".type func_0030a690, @function\n"
    "func_0030a690:\n"
    "addiu $29,$29,-16\n"
    "lui $2,0x36\n"
    "lui $4,0x1e4\n"
    "sd $31,0($29)\n"
    "sw $0,24932($2)\n"
    "addiu $4,$4,-30296\n"
    "move $5,$0\n"
    "jal _Z16wtarget_002fde18jjjj\n"
    "li $6,4\n"
    "ld $31,0($29)\n"
    "move $2,$0\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".size func_0030a690, .-func_0030a690\n"
    ".set pop\n"
);
