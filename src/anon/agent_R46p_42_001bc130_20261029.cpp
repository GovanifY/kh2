
// Agent R46p_42 (2026-10-29): FUN_001bc130 (88 bytes), SLPM_666.75.
// Code: s0 = (IsExec() == 0) ? 0 : 1 via a branch-likely (beqzl with li in the delay slot), then
// GetCurrent()->+4 bits 2..3 test; returns s0 unless the byte-test result is zero, in which case
// v0 = s0 as well. Plain C does not give beqzl, so this is a whole-body asm block.
// The branch-likely is written as beqzl, which gas accepts. The callees have mangled names and no
// function-style row, so they are reached by numeric jal.

void func_001bc130(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "jal 0x1bb4a0\n\t"
        " daddu $16,$0,$0\n\t"
        "beqzl $2,1f\n\t"
        " addiu $16,$0,1\n\t"
        "jal 0x1bbcb0\n\t"
        " nop\n\t"
        "lw $14,8($2)\n\t"
        "lhu $15,4($14)\n\t"
        "srl $15,$15,2\n\t"
        "andi $15,$15,1\n\t"
        "andi $15,$15,0xff\n\t"
        "beqz $15,2f\n\t"
        " daddu $2,$16,$0\n\t"
        "addiu $16,$0,1\n\t"
        "1:\n\t"
        "daddu $2,$16,$0\n\t"
        "2:\n\t"
        "ld $31,8($29)\n\t"
        "ld $16,0($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
