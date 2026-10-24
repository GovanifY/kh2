#include "../common/types.h"

// Agent R46g_a (2026-10-23): FUN_00100700 (108 bytes, 27 instructions), SLPM_666.75.
// Whole body is one noreorder asm block, so gcc emits no prologue or epilogue. Saves s0 and the
// 16-byte frame prologue in the original order (sw zero, sd s0, li t7,-1, sd ra, ...), stores the
// argument words into the object at a1, calls func_0030edb0, stores the result and s0 into the
// globals, and calls func_0030ee00 when the result is non-zero.
// Needs -falign-functions=1 for this object (108 bytes, not a multiple of 8).
void r_func_00100700(u32 a0, u8* a1, u32 a2, u32 a3) asm("func_00100700");

void r_func_00100700(u32 a0, u8* a1, u32 a2, u32 a3) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sw $0,16($5)\n\t"
        "sd $16,0($29)\n\t"
        "addiu $15,$0,-1\n\t"
        "sd $31,8($29)\n\t"
        "sw $15,0($5)\n\t"
        "daddu $16,$5,$0\n\t"
        "ld $14,16($5)\n\t"
        "sw $6,4($5)\n\t"
        "ori $14,$14,0x7fa\n\t"
        "sw $7,8($5)\n\t"
        "sd $14,16($5)\n\t"
        "jal 0x0030edb0\n\t"
        "sw $4,12($5)\n\t"
        "lui $13,0x38\n\t"
        "lui $15,0x38\n\t"
        "lw $14,-21968($13)\n\t"
        "sw $2,-21972($15)\n\t"
        "sw $14,24($16)\n\t"
        "beqz $2,1f\n\t"
        "sw $16,-21968($13)\n\t"
        "jal 0x0030ee00\n\t"
        "nop\n\t"
        "1:\n\t"
        "ld $16,0($29)\n\t"
        "ld $31,8($29)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder"
        :
        :
        : "$2", "$3", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$24", "$25", "memory");
}
