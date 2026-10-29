#include "../common/types.h"

// Agent R46p_108 (2026-10-29): FUN_00283618 (80 bytes, SLPM_666.75).
// Whole-body noreorder asm (form a, noreturn C function). Two calls to 0x139d78 on the word at
// 0x35f2b8 + 852 and + 416; the first uses bnezl (branch-likely, ld s0 in its delay slot), so
// plain C cannot emit it. If the second result is zero, calls 0x2839f0(1).
void func_00283618(void) __attribute__((noreturn));

void func_00283618(void) {
    asm volatile(
        ".set push\n"
        ".set noreorder\n"
        "addiu $29,$29,-16\n"
        "sd $16,0($29)\n"
        "sd $31,8($29)\n"
        "lui $16,0x36\n"
        "lw $4,-3400($16)\n"
        "jal 0x139d78\n"
        "addiu $4,$4,852\n"
        "bnezl $2,3f\n"
        "ld $16,0($29)\n"
        "lw $4,-3400($16)\n"
        "jal 0x139d78\n"
        "addiu $4,$4,416\n"
        "bnez $2,2f\n"
        "addiu $4,$0,1\n"
        "jal 0x2839f0\n"
        "nop\n"
        "2:\n"
        "ld $16,0($29)\n"
        "3:\n"
        "ld $31,8($29)\n"
        "jr $31\n"
        "addiu $29,$29,16\n"
        ".set pop\n"
        ::: "memory");
}
