#include "../common/types.h"

// FUN_00102180 (76 bytes).
// Code: walks a linked list from the word at D-21952 (0x38AA40), next node at +12. For each node
// whose word at +28 is 1, stores the node pointer at arg0 and advances arg0 by 4, and counts it.
// Returns the count.
// Guess: a collector that fills an array with the flagged nodes of the list used by FUN_00102210.
// Matching: the whole body is one noreorder asm block. The bnezl, the loop tail (bne back to the
// top) and the store/advance pair are written in the original order, with the frame-less exit.
u32 func_00102180(u32* a0) {
    register u32* p asm("$4") = a0;
    register u32 ret asm("$2");
    asm volatile(
        ".set noreorder\n"
        "move $13,$0\n"
        "move $2,$0\n"
        "lui $11,0x39\n"
        "li $12,1\n"
        "1:\n"
        "bnezl $13,2f\n"
        "lw $14,12($13)\n"
        "lw $14,-21952($11)\n"
        "2:\n"
        "bnez $14,3f\n"
        "move $13,$14\n"
        "jr $31\n"
        "nop\n"
        "nop\n"
        "3:\n"
        "lw $15,28($14)\n"
        "bne $15,$12,1b\n"
        "nop\n"
        "sw $14,0($4)\n"
        "addiu $2,$2,1\n"
        "b 1b\n"
        "addiu $4,$4,4\n"
        ".set reorder\n"
        : "=r"(ret), "+r"(p) : : "$11", "$12", "$13", "$14", "$15", "memory");
    return ret;
}
