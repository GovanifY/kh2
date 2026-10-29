// Agent R46p_58: FUN_001d3390 (76 bytes), SLPM_666.75.
// Whole-body asm (form b, plain void definition). Saves s0, s1, ra; calls 0x1d3350(0, lui 0x1d6 + -17904)
// and stores its result in s1; calls 0x1d3388(s0), stores s0 at [s1], returns s0.
// Both callees have no functions.tsv row (FUN_001d3388 is 8 bytes), so numeric jal is used.
// Needs -falign-functions=1 (size not a multiple of 8).
void func_001d3390(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "daddu $5,$0,$0\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,16($29)\n\t"
        "daddu $16,$4,$0\n\t"
        "sd $17,8($29)\n\t"
        "lui $4,0x1d6\n\t"
        "jal 0x1d3350\n\t"
        "addiu $4,$4,-17904\n\t"
        "daddu $17,$2,$0\n\t"
        "jal 0x1d3388\n\t"
        "daddu $4,$16,$0\n\t"
        "sw $16,0($17)\n\t"
        "daddu $2,$16,$0\n\t"
        "ld $31,16($29)\n\t"
        "ld $16,0($29)\n\t"
        "ld $17,8($29)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,32\n\t"
        ".set reorder"
        ::: "memory");
}
