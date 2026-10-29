#include "../common/types.h"

// Agent R46p_90: func_002429c0 (60 bytes, SLPM_666.75).
// Whole-body asm. Saves s0, s1, ra; calls the getSaveRam callee (0x1058e8, numeric jal) with
// the delay slot move s1,a1; stores s0 as a halfword at +16800 and s1 at +16802 of the returned
// pointer (the second via t7 = v0 + 16800).

void r_func_002429c0(void) asm("func_002429c0");

void r_func_002429c0(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "sd $16,0($29)\n\t"
        "sd $17,8($29)\n\t"
        "sd $31,16($29)\n\t"
        "daddu $16,$4,$0\n\t"
        "jal 0x1058e8\n\t"
        " daddu $17,$5,$0\n\t"
        "addiu $15,$2,16800\n\t"
        "sh $16,16800($2)\n\t"
        "sh $17,2($15)\n\t"
        "ld $16,0($29)\n\t"
        "ld $17,8($29)\n\t"
        "ld $31,16($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,32\n\t"
        ".set reorder"
        ::: "memory");
}
