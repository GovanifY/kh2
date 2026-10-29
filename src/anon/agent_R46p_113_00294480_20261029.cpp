#include "../common/types.h"

// FUN_00294480 (80 bytes), whole-body asm (form b).
// If byte 6 of a0 equals 2, returns (0 < FUN_001a3570(u16 at a0+0)). Otherwise returns 1 when
// FUN_00181500(u16 at a0+0) is non-zero (via bnezl with li in the delay slot), else 0.
// gcc 3.2 does not emit bnezl from C, so the body is raw asm with numeric jal targets.

void r_FUN_00294480(void) asm("func_00294480");

void r_FUN_00294480(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "addiu $15,$0,2\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "lb $14,6($4)\n\t"
        "beq $14,$15,4f\n\t"
        "daddu $16,$0,$0\n\t"
        "jal 0x181500\n\t"
        "lhu $4,0($4)\n\t"
        "bnezl $2,5f\n\t"
        "addiu $16,$0,1\n\t"
        "5:\n\t"
        "daddu $2,$16,$0\n\t"
        "ld $31,8($29)\n\t"
        "ld $16,0($29)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        "4:\n\t"
        "jal 0x1a3570\n\t"
        "lhu $4,0($4)\n\t"
        "beq $0,$0,5b\n\t"
        "slt $16,$0,$2\n\t"
        ".set reorder"
        ::: "memory");
}
