#include "../common/types.h"

// Agent R46p_23 (2026-10-29): FUN_0019d438 (68 bytes), SLPM_666.75.
// Saves s0 and ra, calls FUN_0019d4a8(a0) with s0 = a0, then sets a0 = s0+4 and a1 = a0 (the beqz
// delay slot). If the call returned 0, tail-jumps to 0x15a638 with s0 restored. Otherwise tail-jumps
// to 0x2c0688 with a0 = [s0+40].
// Whole-body noreorder asm: the tail jumps need the ld restores in their delay-slot order, and the
// s0 move sits in the jal delay slot. Numeric targets are used for the jal/j callees.
void r_FUN_0019d438(void) asm("func_0019d438");

void r_FUN_0019d438(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "jal 0x19d4a8\n\t"
        " daddu $16,$4,$0\n\t"
        "addiu $4,$16,4\n\t"
        "beqz $2,1f\n\t"
        " daddu $5,$4,$0\n\t"
        "lw $4,40($16)\n\t"
        "ld $31,8($29)\n\t"
        "ld $16,0($29)\n\t"
        "j 0x2c0688\n\t"
        " addiu $29,$29,16\n\t"
        "1:\n\t"
        "ld $16,0($29)\n\t"
        "ld $31,8($29)\n\t"
        "j 0x15a638\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        :
        :
        : "memory");
}
