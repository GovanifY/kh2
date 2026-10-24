#include "../common/types.h"

// FUN_00102210 (64 bytes).
// Code: walks a linked list. The start is the word at D-21952 (0x38AA40). Each next node is the word
// at +12 of the current one. Returns the first node whose word at +28 is 1, or 0 when the list ends.
// Guess: a find-first-by-flag query on the same list as FUN_00102180.
// Matching: the whole body is one noreorder asm block. The bnezl loads the next node in its slot,
// the shared return block (move v0,zero; jr ra) is reached by the not-found path and by the beq.
u32 func_00102210(void) {
    register u32 ret asm("$2");
    asm volatile(
        ".set noreorder\n"
        "move $14,$0\n"
        "lui $12,0x39\n"
        "li $13,1\n"
        "1:\n"
        "bnezl $14,2f\n"
        "lw $2,12($14)\n"
        "lw $2,-21952($12)\n"
        "2:\n"
        "bnez $2,3f\n"
        "move $14,$2\n"
        "move $2,$0\n"
        "4:\n"
        "jr $31\n"
        "nop\n"
        "3:\n"
        "lw $15,28($2)\n"
        "beq $15,$13,4b\n"
        "nop\n"
        "b 1b\n"
        "nop\n"
        ".set reorder\n"
        : "=r"(ret) : : "$12", "$13", "$14", "$15", "memory");
    return ret;
}
