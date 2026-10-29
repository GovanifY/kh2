#include "../common/types.h"

// FUN_001ddd30 (84 bytes)
// Code: walks a linked list starting at t5 = 0. While t6 (the next value) is nonzero,
// it checks t6 against a0. On a match it tail-calls 0x1dde40. Otherwise it loops,
// reading the next link from the first node (bnezl, lw in the delay slot) or from a
// global at 0x1da0000 - 7352 on the first pass. When t6 is zero it returns.
// Guess: list search with a tail call on a hit.
// Whole-body asm: the bnezl branch-likely and the tail-call epilogue are not emitted
// by gcc 3.2 from plain C.
void func_001ddd30(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "daddu $13,$0,$0\n\t"
        "sd $31,0($29)\n\t"
        "lui $12,0x1da\n\t"
        "1:\n\t"
        "bnezl $13,2f\n\t"
        "lw $14,20($13)\n\t"
        "lw $14,-7352($12)\n\t"
        "2:\n\t"
        "bnez $14,3f\n\t"
        "daddu $13,$14,$0\n\t"
        "daddu $15,$0,$0\n\t"
        "4:\n\t"
        "andi $15,$15,0xff\n\t"
        "beqz $15,5f\n\t"
        "ld $31,0($29)\n\t"
        "j 0x1dde40\n\t"
        "addiu $29,$29,16\n\t"
        "5:\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        "3:\n\t"
        "beq $14,$4,4b\n\t"
        "addiu $15,$0,1\n\t"
        "b 1b\n\t"
        "nop\n\t"
        ".set reorder\n\t"
        : : : "memory");
}
