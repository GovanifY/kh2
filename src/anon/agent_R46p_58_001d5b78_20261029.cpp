// Agent R46p_58: FUN_001d5b78 (64 bytes), SLPM_666.75.
// Whole-body asm (form b, plain void definition). Computes key = (a0 << 4) | a1, loads the pointer
// at 0x1d5ba70-equivalent (lui 0x1d6, offset -17808), then calls 0x2fd248(key, p+8, [p+4], 8, 0x3217a0)
// with the advanced pointer in a1 set in the jal delay slot. Callee has no functions.tsv row.
// Multiple of 8 bytes, so no align flag is needed.
void func_001d5b78(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "lui $15,0x1d6\n\t"
        "sd $31,0($29)\n\t"
        "sll $4,$4,4\n\t"
        "lw $14,-17808($15)\n\t"
        "or $4,$4,$5\n\t"
        "lui $8,0x32\n\t"
        "addiu $7,$0,8\n\t"
        "lw $6,4($14)\n\t"
        "addiu $8,$8,6048\n\t"
        "addiu $14,$14,8\n\t"
        "jal 0x2fd248\n\t"
        "daddu $5,$14,$0\n\t"
        "ld $31,0($29)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
