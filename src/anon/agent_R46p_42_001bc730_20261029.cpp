
// Agent R46p_42 (2026-10-29): FUN_001bc730 (68 bytes), SLPM_666.75.
// Code: if (a1 < obj->+8) { obj->+108 = a1; obj->+112 = halfword at obj + a1 * 12 + 14; return; }
// otherwise tail-jumps to FUN_001bc720(obj). The ra spill sits before the test and the reload is
// placed in the branch delay path and before the jr, so this is a whole-body asm block.
// The mult is the R5900 three-operand form and is written as .word with the original encoding.
// The size is not a multiple of 8, so the object needs -falign-functions=1.

void func_001bc730(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $31,0($29)\n\t"
        "lw $15,8($4)\n\t"
        "slt $15,$5,$15\n\t"
        "beqz $15,1f\n\t"
        " addiu $15,$0,12\n\t"
        "sw $5,108($4)\n\t"
        ".word 0x00af7818\n\t"          /* mult $15,$5,$15 */
        "ld $31,0($29)\n\t"
        "addu $15,$15,$4\n\t"
        "lhu $14,14($15)\n\t"
        "sw $14,112($4)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        "1:\n\t"
        "ld $31,0($29)\n\t"
        "j 0x1bc720\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
