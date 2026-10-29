#include "../common/types.h"

// Agent R46p_31 (2026-10-29): FUN_001aadb0 (52 bytes), SLPM_666.75.
// Code: frame of 16 bytes, saves s0 and ra. Copies a0 into a1, calls FUN_002362b0 with the
// global pointer 0x01c6cd20 in a0 (lui 0x1c7 + addiu -13024), repeats that a0 move in the delay
// slot after the call, then tail-jumps to FUN_002367c8 with the restores in the jump's delay slot.
// Matching: whole-body noreorder asm with no C locals, so gcc emits no prologue. The asm keeps the
// original order: move a1,a0 first, then sd s0, sd ra, the lui/addiu pair, and the tail j.
// Both callees have no functions.tsv row, so they are reached by numeric jal/j targets.

void func_001aadb0(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "daddu $5,$4,$0\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "lui $16,0x1c7\n\t"
        "addiu $16,$16,-13024\n\t"
        "jal 0x2362b0\n\t"
        " daddu $4,$16,$0\n\t"
        "daddu $4,$16,$0\n\t"
        "ld $31,8($29)\n\t"
        "ld $16,0($29)\n\t"
        "j 0x2367c8\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
