#include "../common/types.h"

// Agent R46p_28 (2026-10-29): FUN_001ac310 (104 bytes, SLPM_666.75).
// Keeps s0 = a0 and s1 = a0+12. If the word at a0 is non-zero, calls 0x23acd8(s1), then copies
// words +4 and +8 of s0 to s1+328 and s1+332 and tail-jumps to 0x23ade0(s1). Otherwise returns.
// Matching: whole-body asm (form a). Numeric jal and j targets (no func_ rows for either callee).

void func_001ac310(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "sd $16,0($29)\n\t"
        "sd $17,8($29)\n\t"
        "sd $31,16($29)\n\t"
        "daddu $16,$4,$0\n\t"
        "addiu $17,$4,12\n\t"
        "lw $15,0($4)\n\t"
        "beqz $15,1f\n\t"
        " daddu $4,$17,$0\n\t"
        "jal 0x23acd8\n\t"
        "nop\n\t"
        "lw $14,8($16)\n\t"
        "daddu $4,$17,$0\n\t"
        "lw $15,4($16)\n\t"
        "ld $31,16($29)\n\t"
        "sw $15,328($17)\n\t"
        "sw $14,332($17)\n\t"
        "ld $16,0($29)\n\t"
        "ld $17,8($29)\n\t"
        "j 0x23ade0\n\t"
        " addiu $29,$29,32\n"
        "1:\n\t"
        "ld $16,0($29)\n\t"
        "ld $17,8($29)\n\t"
        "ld $31,16($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,32\n\t"
        ".set reorder"
        ::: "memory");
}
