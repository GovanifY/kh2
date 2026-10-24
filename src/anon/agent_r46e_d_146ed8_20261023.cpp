#include "../common/types.h"

// FUN_00146ed8 (80 bytes, 20 instructions). Whole body is one noreorder asm block; the function
// is a leaf, so gcc adds no frame. Block order follows the original: entry, sign test, mask test
// (fallthrough sets t7 to the and-result and v0 to 1), the sign-negative block at 146f14, the
// shared "b" to the return, and the zero-byte path that reloads the word and jumps back.
// Pinned: a1 in $5, result v0 in $2. Temps t6=$14, t7=$15.
u32 func_00146ed8(u32 a0, u32 a1) {
    (void)a0;
    register u32 r asm("$2");
    register u32 p asm("$5") = a1;
    asm volatile(
        ".set noreorder\n\t"
        "lbu $15,235($5)\n\t"
        "sll $14,$15,24\n\t"
        "andi $15,$15,0xff\n\t"
        "beqz $15,2f\n\t"
        "sra $14,$14,24\n\t"
        "bltz $14,3f\n\t"
        "lw $14,248($5)\n\t"
        "andi $15,$14,0x10\n\t"
        "beqz $15,4f\n\t"
        "ori $15,$14,0x800\n\t"
        "addiu $15,$0,-2049\n\t"
        "addiu $2,$0,1\n\t"
        "and $15,$14,$15\n\t"
        "1:\n\t"
        "jr $31\n\t"
        "sw $15,248($5)\n\t"
        "3:\n\t"
        "ori $15,$14,0x800\n\t"
        "4:\n\t"
        "b 1b\n\t"
        "daddu $2,$0,$0\n\t"
        "2:\n\t"
        "b 3b\n\t"
        "lw $14,248($5)\n\t"
        ".set reorder\n\t"
        : "=r"(r)
        : "r"(p)
        : "$14", "$15", "memory");
    return r;
}
