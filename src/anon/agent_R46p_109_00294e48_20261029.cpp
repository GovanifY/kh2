#include "../common/types.h"

// Agent R46p_109 (2026-10-29): FUN_00294e48 (92 bytes, align flag), SLPM_666.75.
// Calls FUN_0023f900 on the pointer at 0x36xxxx-2692; if FUN_00292630() is zero, calls FUN_00293db8(1, 0)
// and then FUN_0023fa08 on the same pointer with the result; then sets the byte at -2688 to 1.
// Whole-body noreorder asm: the jal delay-slot lw and the move a1,v0 are kept as in the original.

void r_FUN_00294e48(void) asm("func_00294e48");

void r_FUN_00294e48(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "lui $16,0x36\n\t"
        "jal 0x23f900\n\t"
        "lw $4,-2692($16)\n\t"
        "jal 0x292630\n\t"
        "nop\n\t"
        "addiu $4,$0,1\n\t"
        "bne $2,$0,2f\n\t"
        "daddu $5,$0,$0\n\t"
        "jal 0x293db8\n\t"
        "nop\n\t"
        "lw $4,-2692($16)\n\t"
        "jal 0x23fa08\n\t"
        "daddu $5,$2,$0\n\t"
        "addiu $14,$0,1\n\t"
        "lui $15,0x36\n\t"
        "sb $14,-2688($15)\n\t"
        "2:\n\t"
        "ld $16,0($29)\n\t"
        "ld $31,8($29)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
