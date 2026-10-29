// Agent R46p_86 (2026-10-29): FUN_0022afa0 (68 bytes), SLPM_666.75.
// Whole-body asm (form b): gcc's prologue/delay-slot choices do not reproduce the original, so the
// body is one top-level asm block with the reference words in order, numeric jal/j targets.
void r_FUN_0022afa0(void) asm("func_0022afa0");
#if 0
void r_FUN_0022afa0(void) {
}
#endif
__asm__(
    ".section .text.func_0022afa0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0022afa0\n"
    ".type func_0022afa0, @function\n"
    "func_0022afa0:\n"
    "addiu $29,$29,-16
"
    "sd $16,0($29)
"
    "sd $31,8($29)
"
    "jal 0x224828
"
    "daddu $16,$4,$0
"
    "mtc1 $16,$f0
"
    "lui $15,0x37
"
    "addiu $15,$15,4368
"
    "ld $31,8($29)
"
    "cvt.s.w $f0,$f0
"
    "ld $16,0($29)
"
    "lwc1 $f1,0($15)
"
    "mul.s $f0,$f0,$f1
"
    "cvt.w.s $f1,$f0
"
    "mfc1 $4,$f1
"
    "j 0x22afe8
"
    "addiu $29,$29,16
"
    ".set pop\n"
    ".size func_0022afa0, .-func_0022afa0\n"
    ".text\n");
