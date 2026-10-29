#include "../common/types.h"

// Asm label alias: registers func_002233f0 with this file (no C definition is emitted).
void r_FUN_002233f0(void) asm("func_002233f0");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
void r_FUN_002233f0(void) {
}
#endif

// FUN_002233f0 (88 bytes). Top-level asm, so gcc emits no prologue or epilogue.
// Two calls to FUN_002fdfc8: the first with a0 = 0x370000 + 3032 and a1 = the original a0,
// the second with a0 = 0x370000 + 3064, a1 = the original a1 and a2 = the original a2.
// The original a1 and a2 are saved in s0 and s1 before the first call. A break follows the
// second jal, which the callee does not return past, so the break is never reached.
// The callee has no func_ row, so both calls are numeric jal in the asm.
__asm__(
    ".section .text.func_002233f0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002233f0\n"
    ".type func_002233f0, @function\n"
    "func_002233f0:\n"
    "addiu $29,$29,-32\n"
    "daddu $15,$4,$0\n"
    "sd $16,0($29)\n"
    "lui $4,0x37\n"
    "sd $17,8($29)\n"
    "addiu $4,$4,3032\n"
    "sd $31,16($29)\n"
    "daddu $16,$5,$0\n"
    "daddu $5,$15,$0\n"
    "jal 0x2fdfc8\n"
    "daddu $17,$6,$0\n"
    "lui $4,0x37\n"
    "daddu $5,$16,$0\n"
    "daddu $6,$17,$0\n"
    "jal 0x2fdfc8\n"
    "addiu $4,$4,3064\n"
    "break\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_002233f0, .-func_002233f0\n"
    ".text\n");
