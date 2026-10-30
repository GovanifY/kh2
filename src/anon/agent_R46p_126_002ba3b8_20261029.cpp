#include "../common/types.h"

void r_FUN_002ba3b8(void) asm("func_002ba3b8");
#if 0
void r_FUN_002ba3b8(void) {
}
#endif

// Agent R46p_126: FUN_002ba3b8 (44 bytes), SLPM_666.75.
// Code: 8 register args (a4..a7 are t0..t3). Sets the 9th argument slot (sp+0) to -1, moves
// the register args (a7 = old a6, a6 = old a5, a5 = sp), then jal FUN_002ba3e8 and returns its
// result via the usual frame restore. Frame of 32 bytes, ra at +16.
// Matching: one file-scope asm block (the R46f pattern). A C local would take a 48-byte frame and
// gcc puts the outgoing slot above it, so the -1 must live at sp+0 in asm.
__asm__(
    ".section .text.func_002ba3b8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002ba3b8\n"
    ".type func_002ba3b8, @function\n"
    "func_002ba3b8:\n"
    "addiu $29,$29,-32\n"
    "li $15,-1\n"
    "move $11,$10\n"
    "sd $31,16($29)\n"
    "move $10,$9\n"
    "sw $15,0($29)\n"
    "jal 0x002ba3e8\n"
    "move $9,$29\n"
    "ld $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_002ba3b8, .-func_002ba3b8\n"
    ".text\n");
