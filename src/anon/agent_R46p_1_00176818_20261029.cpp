#include "../common/types.h"

// Agent R46p_1 (2026-10-29): FUN_00176818 (76 bytes), SLPM_666.75.
// If the word at +360 of arg0 has bit 0x10 clear, calls func_0017f540(arg0 + 320, 4, double 0.0 built
// from the float at D_00370000-15168 in $f12 and zero in $f13). Then tail-calls func_001842c0(arg0).
// Matching: whole body as one file-scope asm block with the original instruction order; the branch
// delay slots hold the addiu and the lwc1, as in the original.
void r_FUN_00176818(void) asm("func_00176818");
#if 0
void r_FUN_00176818(void) {
}
#endif

__asm__(
    ".section .text.func_00176818,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00176818\n"
    ".type func_00176818, @function\n"
    "func_00176818:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "daddu $16,$4,$0\n"
    "lw $15,360($4)\n"
    "andi $15,$15,0x10\n"
    "bnez $15,1f\n"
    "addiu $4,$4,320\n"
    "lui $15,0x37\n"
    "mtc1 $0,$f13\n"
    "addiu $15,$15,-15168\n"
    "addiu $5,$0,4\n"
    "jal func_0017f540\n"
    "lwc1 $f12,0($15)\n"
    "1:\n"
    "daddu $4,$16,$0\n"
    "ld $31,8($29)\n"
    "ld $16,0($29)\n"
    "j func_001842c0\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_00176818, .-func_00176818\n"
    ".text\n");
