#include "../common/types.h"

// Agent R46k_r (2026-10-23): FUN_0016f8d0 (96 bytes), SLPM_666.75.
// Calls FUN_0016f930(a0) into s0; if the result is 2400, calls FUN_0016f930(0) again.
// Then 2410 stores s0 to D_004f63a8 and 2420 stores s0 to D_004f63ac; other results return.
// Whole-function noreorder body (out-of-line store blocks reached by b, as in the original).
void r_FUN_0016f8d0(void) asm("func_0016f8d0");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
void r_FUN_0016f8d0(void) {
}
#endif

__asm__(
    ".section .text.func_0016f8d0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0016f8d0\n"
    ".type func_0016f8d0, @function\n"
    "func_0016f8d0:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "jal func_0016f930\n"
    "move $16,$4\n"
    "addiu $15,$0,2400\n"
    "bne $2,$15,1f\n"
    "move $4,$0\n"
    "jal func_0016f930\n"
    "nop\n"
    "1: addiu $15,$0,2410\n"
    "beq $2,$15,3f\n"
    "addiu $15,$0,2420\n"
    "beq $2,$15,2f\n"
    "lui $15,0x4f\n"
    "4: ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    "2: b 4b\n"
    "sw $16,25516($15)\n"
    "3: lui $15,0x4f\n"
    "b 4b\n"
    "sw $16,25512($15)\n"
    ".set pop\n"
    ".size func_0016f8d0, .-func_0016f8d0\n"
    ".text\n");
