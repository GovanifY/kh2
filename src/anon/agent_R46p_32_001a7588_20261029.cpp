#include "../common/types.h"

// Agent R46p_32 (2026-10-29): FUN_001a7588 (80 bytes), SLPM_666.75.
// Code: frame of 48 bytes. Calls func_001d35e0(&tmp, a0, a1) with a2-less args: a1 = a0, a2 = a1,
// a0 = &tmp (16-byte stack slot at sp). Returns the word at tmp+20 in v0. If the call returned
// nonzero and dest (a2) is not sp, copies 16 bytes from tmp to dest with lq/sq (beql delay slot skip).
// func_001d35e0 has no functions.tsv row, so it is reached by a numeric jal in asm.
// Form: whole-body asm (form a), noreturn C function with the full frame inside the asm.
void func_001a7588(void* a0, void* a1, void* a2) __attribute__((noreturn));
void func_001a7588(void* a0, void* a1, void* a2) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-48\n\t"
        "daddu $15,$5,$0\n\t"
        "sd $16,32($29)\n\t"
        "daddu $5,$4,$0\n\t"
        "sd $31,40($29)\n\t"
        "daddu $4,$29,$0\n\t"
        "daddu $16,$6,$0\n\t"
        "jal 0x1d35e0\n\t"
        " daddu $6,$15,$0\n\t"
        "beqz $2,2f\n\t"
        " lw $2,20($29)\n\t"
        "beql $16,$29,1f\n\t"
        " ld $16,32($29)\n\t"
        "lq $8,0($29)\n\t"
        "sq $8,0($16)\n\t"
        "lw $2,20($29)\n"
        "2:\n\t"
        "ld $16,32($29)\n"
        "1:\n\t"
        "ld $31,40($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,48\n\t"
        ".set reorder"
        ::: "memory");
}
