#include "../common/types.h"

// Agent R46p_56 (2026-10-29): FUN_001d69d0 (88 bytes), SLPM_666.75.
// Whole-body asm. Calls the mangled dk::GAUGE::destroy(int) with only the this pointer, then
// YS::LOCKON::reset_player on this+2752. If this->ptr2804->word1164 is nonzero, calls
// func_0013dde8(0). Then calls func_001befa8(this), clears this->ptr2804 and the word at
// 0x003527E0. Plain C gives lui+ori for the global and cannot place ld ra before the store,
// so the epilogue order needs asm.
void r_FUN_001d69d0(void) asm("func_001d69d0");
#if 0
void r_FUN_001d69d0(void) {
}
#endif

__asm__(
    ".section .text.func_001d69d0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001d69d0\n"
    ".type func_001d69d0, @function\n"
    "func_001d69d0:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "jal 0x1d6a28\n"
    "daddu $16,$4,$0\n"
    "jal 0x19ca20\n"
    "addiu $4,$16,2752\n"
    "lw $14,2804($16)\n"
    "lw $15,1164($14)\n"
    "beqz $15,1f\n"
    "daddu $4,$0,$0\n"
    "jal 0x13dde8\n"
    "nop\n"
    "1:\n"
    "jal 0x1befa8\n"
    "daddu $4,$16,$0\n"
    "sw $0,2804($16)\n"
    "lui $15,0x35\n"
    "ld $31,8($29)\n"
    "sw $0,10208($15)\n"
    "ld $16,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001d69d0, .-func_001d69d0\n"
    ".text\n");
