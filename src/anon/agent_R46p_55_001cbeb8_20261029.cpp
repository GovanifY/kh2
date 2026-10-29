// Agent R46p_55: FUN_001cbeb8 (100 bytes), SLPM_666.75.
// Whole-body asm (form b, plain void definition). Reads the pointer at 0x351fe4; if non-null,
// calls 0x1cbc50(ptr, a1 * 16 + 0x36e180, 0, 0) and sets the flag bits at result+40, stores
// 0x1cba90 at result+16. Returns the object pointer (or 0). Callee has no functions.tsv row,
// so it is reached with a numeric jal. Needs -falign-functions=1 (size not a multiple of 8).
void func_001cbeb8(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "lui $15,0x35\n\t"
        "sd $31,0($29)\n\t"
        "daddu $6,$4,$0\n\t"
        "daddu $13,$0,$0\n\t"
        "lw $14,8164($15)\n\t"
        "sll $15,$5,4\n\t"
        "beq $14,$0,2f\n\t"
        "daddu $4,$14,$0\n\t"
        "lui $5,0x37\n\t"
        "daddu $7,$0,$0\n\t"
        "addiu $5,$5,-7808\n\t"
        "jal 0x1cbc50\n\t"
        "addu $5,$15,$5\n\t"
        "lw $14,40($2)\n\t"
        "lui $15,0x1d\n\t"
        "addiu $15,$15,-17776\n\t"
        "daddu $13,$2,$0\n\t"
        "ori $14,$14,3\n\t"
        "sw $15,16($2)\n\t"
        "sw $14,40($2)\n"
        "2:\n\t"
        "ld $31,0($29)\n\t"
        "daddu $2,$13,$0\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
