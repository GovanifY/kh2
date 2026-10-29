#include "../common/types.h"

// FUN_00198738 (108 bytes). If the word at +1968 of a0 is non-zero, calls 0x168b88(obj, 22, v, 0)
// where v is assembled from four signed bytes at a1 (b0 | b3<<24 | b2<<16 | b1<<8); a non-zero
// result returns the word at +8 of it, else 0. A zero object pointer returns 0.
// Whole-body asm in a noreturn function: beql and the out-of-line zero return need the asm form.
// The callee has no functions.tsv row, so jal is numeric.
void func_00198738(u32 a0, u32 a1) __attribute__((noreturn));
void func_00198738(u32 a0, u32 a1) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "daddu $12,$5,$0\n\t"
        "sd $31,0($29)\n\t"
        "addiu $5,$0,22\n\t"
        "lw $15,1968($4)\n\t"
        "beq $15,$0,2f\n\t"
        "daddu $4,$15,$0\n\t"
        "lb $13,1($12)\n\t"
        "daddu $7,$0,$0\n\t"
        "lb $14,3($12)\n\t"
        "lb $15,2($12)\n\t"
        "sll $13,$13,8\n\t"
        "lb $6,0($12)\n\t"
        "sll $14,$14,24\n\t"
        "sll $15,$15,16\n\t"
        "or $6,$6,$14\n\t"
        "or $15,$15,$13\n\t"
        "jal 0x168b88\n\t"
        "or $6,$6,$15\n\t"
        "beql $2,$0,3f\n\t"
        "daddu $2,$0,$0\n\t"
        "lw $2,8($2)\n\t"
        "3:\n\t"
        "ld $31,0($29)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        "2:\n\t"
        "b 3b\n\t"
        "daddu $2,$0,$0\n\t"
        ".set reorder"
        ::: "memory");
}
