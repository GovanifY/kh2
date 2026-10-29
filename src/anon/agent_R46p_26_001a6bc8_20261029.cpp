#include "../common/types.h"

// FUN_001a6bc8 (108 bytes). Calls 0x1b3b70(a0, a1, 4, a2) (numeric jal, no functions.tsv row),
// then sets up the object at a0: word +1536 = (w & ~0x78) | 8, word +1416 |= 0x100,
// word +2748 |= 4, word +0 = 0x00350910, word +944 = 3. Returns void.
// Whole-body asm in a noreturn function: the original moves s0 in the jal delay slot and
// loads ra before the stores, which plain C does not reproduce.
void func_001a6bc8(u32 a0, u32 a1, u32 a2) __attribute__((noreturn));
void func_001a6bc8(u32 a0, u32 a1, u32 a2) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "daddu $7,$6,$0\n\t"
        "sd $16,0($29)\n\t"
        "addiu $6,$0,4\n\t"
        "sd $31,8($29)\n\t"
        "jal 0x1b3b70\n\t"
        "daddu $16,$4,$0\n\t"
        "lw $13,1536($16)\n\t"
        "addiu $15,$0,-121\n\t"
        "lw $12,1416($16)\n\t"
        "and $13,$13,$15\n\t"
        "lw $14,2748($16)\n\t"
        "lui $15,0x35\n\t"
        "ld $31,8($29)\n\t"
        "addiu $15,$15,2320\n\t"
        "ori $12,$12,0x100\n\t"
        "sw $15,0($16)\n\t"
        "ori $14,$14,4\n\t"
        "ori $13,$13,8\n\t"
        "sw $14,2748($16)\n\t"
        "addiu $15,$0,3\n\t"
        "sw $12,1416($16)\n\t"
        "sw $15,944($16)\n\t"
        "sw $13,1536($16)\n\t"
        "ld $16,0($29)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
