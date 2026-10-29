#include "../common/types.h"

// FUN_001942b8 (96 bytes): saves s0..s2 and ra, then walks 16 words at a0+1976 (counter in s1 from 15 down
// to 0). Each non-zero word v is passed to FUN_001dcb98(v, a0+1880). The loop back edge is bgezl with the
// next word load in its delay slot, which gcc 3.2 does not emit, so the whole body is a noreorder asm block
// in a noreturn function. Registers are numeric, and the callee is a numeric jal target.
void func_001942b8(u32 a0) {
    register u32 r4 asm("$4") = a0;
    asm volatile(
        ".set noreorder\n"
        "addiu $29,$29,-32\n"
        "sd $16,0($29)\n"
        "sd $17,8($29)\n"
        "sd $18,16($29)\n"
        "addiu $16,$4,1976\n"
        "sd $31,24($29)\n"
        "addiu $17,$0,15\n"
        "daddu $18,$4,$0\n"
        "lw $15,0($16)\n"
        "1:\n"
        "addiu $16,$16,4\n"
        "beqz $15,2f\n"
        "daddu $4,$15,$0\n"
        "jal 0x1dcb98\n"
        "addiu $5,$18,1880\n"
        "2:\n"
        "addiu $17,$17,-1\n"
        "bgezl $17,1b\n"
        "lw $15,0($16)\n"
        "ld $16,0($29)\n"
        "ld $17,8($29)\n"
        "ld $18,16($29)\n"
        "ld $31,24($29)\n"
        "jr $31\n"
        "addiu $29,$29,32\n"
        ".set reorder\n"
        : : "r"(r4) : "memory");
}
