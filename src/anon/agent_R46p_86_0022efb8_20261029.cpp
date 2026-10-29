// Agent R46p_86 (2026-10-29): FUN_0022efb8 (96 bytes), SLPM_666.75.
// Whole-body asm (form b): gcc's prologue/delay-slot choices do not reproduce the original, so the
// body is one top-level asm block with the reference words in order, numeric jal/j targets.
void r_FUN_0022efb8(void) asm("func_0022efb8");
#if 0
void r_FUN_0022efb8(void) {
}
#endif
__asm__(
    ".section .text.func_0022efb8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0022efb8\n"
    ".type func_0022efb8, @function\n"
    "func_0022efb8:\n"
    "addiu $29,$29,-16
"
    "sd $16,0($29)
"
    "sd $31,8($29)
"
    "daddu $16,$4,$0
"
    "jal 0x2282f0
"
    "lh $4,4($4)
"
    "bnezl $2,1f
"
    "ld $16,0($29)
"
    "jal 0x227d10
"
    "lh $4,12($16)
"
    "lh $14,4($16)
"
    "sw $14,12($2)
"
    "lh $14,10($16)
"
    "lh $15,4($16)
"
    "addu $15,$15,$14
"
    "sw $15,16($2)
"
    "lbu $14,8($16)
"
    "sb $14,20($2)
"
    "lbu $15,9($16)
"
    "sb $15,21($2)
"
    "ld $16,0($29)
"
    "1:
"
    "ld $31,8($29)
"
    "jr $31
"
    "addiu $29,$29,16
"
    ".set pop\n"
    ".size func_0022efb8, .-func_0022efb8\n"
    ".text\n");
