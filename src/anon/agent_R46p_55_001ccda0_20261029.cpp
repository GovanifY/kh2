// Agent R46p_55: FUN_001ccda0 (76 bytes), SLPM_666.75.
// Whole-body asm (form b, plain void definition). Calls 0x1c6ee8(a0), then loops on
// 0x1c16f0(obj->+2548, result) while the result is non-zero (bnezl with lw in the delay slot),
// then loops on 0x186078(result) while non-zero. Returns 0. Callees have no functions.tsv row,
// so they are reached with numeric jal. Needs -falign-functions=1 (size not a multiple of 8).
void func_001ccda0(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "jal 0x1c6ee8\n\t"
        "daddu $16,$4,$0\n\t"
        "daddu $2,$0,$0\n\t"
        "lw $4,2548($16)\n"
        "1:\n\t"
        "jal 0x1c16f0\n\t"
        "daddu $5,$2,$0\n\t"
        "bnel $2,$0,1b\n\t"
        "lw $4,2548($16)\n\t"
        "daddu $2,$0,$0\n"
        "2:\n\t"
        "jal 0x186078\n\t"
        "daddu $4,$2,$0\n\t"
        "bne $2,$0,2b\n\t"
        "ld $31,8($29)\n\t"
        "ld $16,0($29)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
