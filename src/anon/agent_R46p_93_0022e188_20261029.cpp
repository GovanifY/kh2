// Agent R46p_93 (2026-10-29): FUN_0022e188 (108 bytes), SLPM_666.75.
// Whole-body asm (form b): the original delay-slot and prologue order is kept, numeric jal targets.
void r_FUN_0022e188(void) asm("func_0022e188");
#if 0
void r_FUN_0022e188(void) {
}
#endif

__asm__(
    ".section .text.func_0022e188,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0022e188\n"
    ".type func_0022e188, @function\n"
    "func_0022e188:\n"
    "addiu $29,$29,-32\n"
    "lui $5,0x37\n"
    "sd $16,0($29)\n"
    "addiu $5,$5,4584\n"
    "sd $17,8($29)\n"
    "lui $16,0x1db\n"
    "sd $31,16($29)\n"
    "sb $0,-9536($16)\n"
    "daddu $17,$4,$0\n"
    "addiu $16,$16,-9536\n"
    "jal 0x2feee8\n"
    "daddu $4,$16,$0\n"
    "daddu $4,$16,$0\n"
    "jal 0x2feee8\n"
    "daddu $5,$17,$0\n"
    "lui $5,0x37\n"
    "daddu $4,$16,$0\n"
    "jal 0x2feee8\n"
    "addiu $5,$5,4600\n"
    "jal 0x2ff3fc\n"
    "daddu $4,$16,$0\n"
    "daddu $2,$16,$0\n"
    "ld $17,8($29)\n"
    "ld $16,0($29)\n"
    "ld $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_0022e188, .-func_0022e188\n"
    ".text\n"
);
