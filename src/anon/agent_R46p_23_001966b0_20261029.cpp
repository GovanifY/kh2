#include "../common/types.h"

// Agent R46p_23 (2026-10-29): FUN_001966b0 (92 bytes), SLPM_666.75.
// Stores -1 (halfword) into a table entry at 0x32bb30 + a0*4 + 7928, loads a word from 0x1c61b08 as
// a base, then calls FUN_00196388(a0*2 + base + 2 byte, +3 byte). A negative result returns; otherwise the
// result is tail-called into 0x1963f8 with the ra restore in its delay slot.
// Whole-body noreorder asm (form b-style body, no C locals). Callees are numeric jal/j targets.
void r_FUN_001966b0(void) asm("func_001966b0");

void r_FUN_001966b0(void) {
    asm volatile(
        ".set noreorder\n\t"
        "lui $15,0x33\n\t"
        "sll $13,$4,2\n\t"
        "addiu $15,$15,-17616\n\t"
        "lui $14,0x1c6\n\t"
        "addu $13,$13,$15\n\t"
        "lw $12,6920($14)\n\t"
        "addiu $29,$29,-16\n\t"
        "addiu $15,$0,-1\n\t"
        "sd $31,0($29)\n\t"
        "sll $4,$4,1\n\t"
        "sh $15,7928($13)\n\t"
        "addu $4,$4,$12\n\t"
        "lbu $5,3($4)\n\t"
        "jal 0x196388\n\t"
        " lbu $4,2($4)\n\t"
        "bltz $2,1f\n\t"
        " move $4,$2\n\t"
        "ld $31,0($29)\n\t"
        "j 0x1963f8\n\t"
        " addiu $29,$29,16\n\t"
        "1:\n\t"
        "ld $31,0($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        :
        :
        : "memory");
}
