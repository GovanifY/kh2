#include "../common/types.h"

// Agent R46k_r (2026-10-23): FUN_001712b0 (72 bytes), SLPM_666.75.
// Reads the object pointer at a0, takes the float at a0+4 as $f14 and the word at obj+2040.
// If bit 0x10 of that word is set, returns. Otherwise tail-calls FUN_001ad990 with
// $f12 = 0.0, $f13 = the float at 0x37xxxx, and a0 = obj + 2092.
// Whole-function noreorder body, so ra is restored between the lwc1 and the tail jump.
void r_FUN_001712b0(void) asm("func_001712b0");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
void r_FUN_001712b0(void) {
}
#endif

__asm__(
    ".section .text.func_001712b0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001712b0\n"
    ".type func_001712b0, @function\n"
    "func_001712b0:\n"
    "addiu $29,$29,-16\n"
    "sd $31,0($29)\n"
    "lw $14,0($4)\n"
    "lwc1 $f14,4($4)\n"
    "lw $15,2040($14)\n"
    "andi $15,$15,0x10\n"
    "bnez $15,1f\n"
    "addiu $4,$14,2092\n"
    "lui $15,0x37\n"
    "mtc1 $0,$f12\n"
    "addiu $15,$15,-15204\n"
    "ld $31,0($29)\n"
    "lwc1 $f13,0($15)\n"
    "j func_001ad990\n"
    "addiu $29,$29,16\n"
    "1: ld $31,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001712b0, .-func_001712b0\n"
    ".text\n");
