#include "../common/types.h"

// Agent R46p_57 (2026-10-29): FUN_001d4ef0 (80 bytes), SLPM_666.75.
// Frame of 32 bytes, saves s0, s1, ra. s0 = a0, s1 = a1. Calls func_00321728(a0 + 56, a1[0], 1), then
// bumps the byte at result+1 and tail-jumps to func_001d4f40(s0, halfword at s1+66).
// Whole-body noreorder asm in a noreturn C function (form a): the tail jump sits between the restores
// and the jal delay slot holds the li of the constant 1.
void func_001d4ef0(u8* a0, u8* a1) __attribute__((noreturn));
void func_001d4ef0(u8* a0, u8* a1) {
    __asm__ volatile(
        ".set\tnoreorder\n\t"
        "addiu\t$29,$29,-32\n\t"
        "sd\t$16,0($29)\n\t"
        "sd\t$17,8($29)\n\t"
        "sd\t$31,16($29)\n\t"
        "daddu\t$16,$4,$0\n\t"
        "daddu\t$17,$5,$0\n\t"
        "addiu\t$4,$4,56\n\t"
        "lbu\t$6,0($5)\n\t"
        "jal\t0x321728\n\t"
        "addiu\t$5,$0,1\n\t"
        "lbu\t$6,1($2)\n\t"
        "daddu\t$4,$16,$0\n\t"
        "ld\t$16,0($29)\n\t"
        "addiu\t$15,$6,1\n\t"
        "ld\t$31,16($29)\n\t"
        "sb\t$15,1($2)\n\t"
        "lhu\t$5,66($17)\n\t"
        "ld\t$17,8($29)\n\t"
        "j\t0x1d4f40\n\t"
        "addiu\t$29,$29,32\n\t"
        ".set\treorder\n\t");
}
