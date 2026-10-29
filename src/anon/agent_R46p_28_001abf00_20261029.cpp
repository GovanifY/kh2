#include "../common/types.h"

// Agent R46p_28 (2026-10-29): FUN_001abf00 (52 bytes, SLPM_666.75).
// Returns 0. If the word at a0 equals 1, calls the object method at 0x239d10 with a0+4.
// Matching: whole-body asm (form a). The jal target is numeric because 0x239d10 has only a mangled name.
// Needs -falign-functions=1 (52 bytes).

void func_001abf00(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "addiu $14,$4,4\n\t"
        "sd $31,0($29)\n\t"
        "addiu $15,$0,1\n\t"
        "daddu $2,$0,$0\n\t"
        "lw $13,0($4)\n\t"
        "bne $13,$15,1f\n\t"
        " daddu $4,$14,$0\n\t"
        "jal 0x239d10\n\t"
        "nop\n"
        "1:\n\t"
        "ld $31,0($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
