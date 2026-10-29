#include "../common/types.h"

// Agent R46p_38 (2026-10-29): FUN_001bba30 (88 bytes), SLPM_666.75.
// Code: frame of 32 bytes, two zeroed stack words, reads a1 = word at a0+72. If a1 is zero returns 0.
// Otherwise t6 = byte at (*(a0+8)) + 12; if t6 != 0 calls 0x1d5370(sp) and 0x2534e0(buf[1], buf[0], t6-1)
// and returns 1; else returns 0.
// Matching: whole-body asm. Both callees have no functions.tsv row, so they are reached by numeric jal.
// The t6-1 value is set in the bnez delay slot and stays in $6 across the first call.
void func_001bba30(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "sd $31,16($29)\n\t"
        "sw $0,0($29)\n\t"
        "sw $0,4($29)\n\t"
        "lw $5,72($4)\n\t"
        "beqz $5,5f\n\t"
        "daddu $2,$0,$0\n\t"
        "lw $15,8($4)\n\t"
        "lbu $14,12($15)\n\t"
        "bnez $14,6f\n\t"
        "addiu $6,$14,-1\n\t"
        "daddu $2,$0,$0\n\t"
        "5:\n\t"
        "ld $31,16($29)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,32\n\t"
        "6:\n\t"
        "jal 0x1d5370\n\t"
        "daddu $4,$29,$0\n\t"
        "lw $4,4($29)\n\t"
        "jal 0x2534e0\n\t"
        "lw $5,0($29)\n\t"
        "b 5b\n\t"
        "addiu $2,$0,1\n\t"
        ".set reorder"
        ::: "memory");
}
