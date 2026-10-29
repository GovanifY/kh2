// Agent R46p_55: FUN_001d23e0 (52 bytes), SLPM_666.75.
// Whole-body asm (form b, plain void definition). Loads a1 from the word at 0x1d5ba04 (the
// D_01d60000 base, lui only), then calls 0x2fd248(a0, a1+8, [a1+4], 12, 0x321698) with the 5th
// argument in t0. Callee has no functions.tsv row, so it is reached with a numeric jal.
// Needs -falign-functions=1 (size not a multiple of 8).
void func_001d23e0(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "lui $15,0x1d6\n\t"
        "sd $31,0($29)\n\t"
        "lui $8,0x32\n\t"
        "lw $5,-17916($15)\n\t"
        "addiu $8,$8,5784\n\t"
        "addiu $7,$0,12\n\t"
        "lw $6,4($5)\n\t"
        "jal 0x2fd248\n\t"
        "addiu $5,$5,8\n\t"
        "ld $31,0($29)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
