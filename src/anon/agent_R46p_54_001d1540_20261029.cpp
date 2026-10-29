#include "../common/types.h"

// FUN_001d1540 (92 bytes), whole-body asm.
// Saves s0/ra, shifts a2/a3 into the jal arguments (jal 0x177dc8 has no functions.tsv row),
// ORs 0x400 into the word at +1416, stores the vtable-like constant at +0, then tail-calls
// 0x1befd8 with a1 = 0x370000 - 7256 and a2 = 2.
// Matching: the prologue sd order and the move in the jal delay slot need the raw asm form.
void func_001d1540(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "daddu $8,$7,$0\n\t"
        "sd $16,0($29)\n\t"
        "daddu $7,$6,$0\n\t"
        "sd $31,8($29)\n\t"
        "addiu $6,$0,8\n\t"
        "jal 0x177dc8\n\t"
        " daddu $16,$4,$0\n\t"
        "lw $13,1416($16)\n\t"
        "lui $14,0x400\n\t"
        "lui $15,0x35\n\t"
        "lw $4,2884($16)\n\t"
        "or $13,$13,$14\n\t"
        "ld $31,8($29)\n\t"
        "addiu $15,$15,9400\n\t"
        "sw $13,1416($16)\n\t"
        "sw $15,0($16)\n\t"
        "lui $5,0x37\n\t"
        "addiu $5,$5,-7256\n\t"
        "addiu $6,$0,2\n\t"
        "ld $16,0($29)\n\t"
        "j 0x1befd8\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
