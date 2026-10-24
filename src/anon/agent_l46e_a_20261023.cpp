#include "../common/types.h"

// FUN_00102a08 (48 bytes).
// Code: counts the nodes of a linked list. The first node is the word at +8 of arg0; each next
// node is the word at +56 of the current one. Stops at a zero link and returns the count.
// Guess: a list-length query.
// Matching: the whole body is one noreorder asm block: move v0/t6 zero, bnezl on t6 with the
// +56 load in its slot, the +8 load otherwise, bnez to the loop tail (b back with addiu in its slot).
u32 func_00102a08(u8* a0) {
    register u8* p asm("$4") = a0;
    register u32 ret asm("$2");
    asm volatile(
        ".set noreorder\n"
        "move $2,$0\n"
        "move $14,$0\n"
        "1:\n"
        "bnezl $14,2f\n"
        "lw $15,56($14)\n"
        "lw $15,8($4)\n"
        "2:\n"
        "bnez $15,3f\n"
        "move $14,$15\n"
        "jr $31\n"
        "nop\n"
        "nop\n"
        "3:\n"
        "b 1b\n"
        "addiu $2,$2,1\n"
        ".set reorder\n"
        : "=r"(ret) : "r"(p) : "$14", "$15", "memory");
    return ret;
}
