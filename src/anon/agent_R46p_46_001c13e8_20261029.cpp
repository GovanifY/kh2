#include "../common/types.h"

// Agent R46p_46 (2026-10-29): FUN_001c13e8 (60 bytes), SLPM_666.75.
// Saves s0 and ra; s0 = a0. Calls FUN_001dc920(word at a0), then FUN_00105110(word at s0+48)
// with s0 += 20 in the jal delay slot, then FUN_001db7d0(s0). Tail-ish: returns void.
// Form: whole-body asm. FUN_001db7d0 has a layout row but no functions.tsv row, so it is reached
// by a numeric jal, which plain C cannot emit.
void r_FUN_001c13e8(void) asm("func_001c13e8");
#if 0
void r_FUN_001c13e8(void) {
}
#endif

__asm__(
    ".section .text.func_001c13e8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001c13e8\n"
    ".type func_001c13e8, @function\n"
    "func_001c13e8:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "daddu $16,$4,$0\n"
    "jal 0x1dc920\n"
    "lw $4,0($4)\n"
    "lw $4,48($16)\n"
    "jal 0x105110\n"
    "addiu $16,$16,20\n"
    "jal 0x1db7d0\n"
    "daddu $4,$16,$0\n"
    "ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001c13e8, .-func_001c13e8\n"
    ".text\n");
