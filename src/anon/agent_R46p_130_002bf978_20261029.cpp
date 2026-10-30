#include "../common/types.h"

// Agent R46p_130 (2026-10-29): FUN_002bf978 (96 bytes), SLPM_666.75.
// s = 0; loop: s = func_002be908(s); if s == 0 return; if (word at s+1416) & 0x80000000, call FUN_002bf8f0(s).
// Matching: whole-body asm (form b). FUN_002bf8f0 has no registry row yet, so it is a numeric jal.
void r_FUN_002bf978(void) asm("func_002bf978");
#if 0
void r_FUN_002bf978(void) {
}
#endif

__asm__(
    ".section .text.func_002bf978,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002bf978\n"
    ".type func_002bf978, @function\n"
    "func_002bf978:\n"
    "addiu $29,$29,-32\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $31,16($29)\n"
    "daddu $16,$0,$0\n"
    "lui $17,0x8000\n"
    "1:\n"
    "jal func_002be908\n"
    "daddu $4,$16,$0\n"
    "daddu $16,$2,$0\n"
    "bne $2,$0,2f\n"
    "daddu $4,$2,$0\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    "2:\n"
    "lw $15,1416($16)\n"
    "and $15,$15,$17\n"
    "beq $15,$0,1b\n"
    "nop\n"
    "jal 0x2bf8f0\n"
    "nop\n"
    "beq $0,$0,1b\n"
    "nop\n"
    ".set pop\n"
    ".size func_002bf978, .-func_002bf978\n"
);
