// Agent R46p_93 (2026-10-29): FUN_00241850 (104 bytes), SLPM_666.75.
// Whole-body asm (form b). Two paths on a1: a1 == 0 loads a word at 0x36xxxx base+4 and copies
// 8 bytes with ldl/ldr/sdl/sdr; otherwise it tail-calls 0x2fde18 with a2 = 8 and a0 = base + a0*32 + 32.
// Numeric j/jal targets and local labels keep the bytes exact.
void r_FUN_00241850(void) asm("func_00241850");
#if 0
void r_FUN_00241850(void) {
}
#endif

__asm__(
    ".section .text.func_00241850,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00241850\n"
    ".type func_00241850, @function\n"
    "func_00241850:\n"
    "addiu $29,$29,-16\n"
    "lui $15,0x36\n"
    "sd $31,0($29)\n"
    "daddu $14,$5,$0\n"
    "sll $12,$4,5\n"
    "addiu $5,$0,255\n"
    "beq $14,$0,2f\n"
    "lw $13,-4964($15)\n"
    "lui $15,0x36\n"
    "ld $31,0($29)\n"
    "lw $4,-4972($15)\n"
    "addiu $6,$0,8\n"
    "addu $4,$4,$12\n"
    "addiu $4,$4,32\n"
    "j 0x2fde18\n"
    "addiu $29,$29,16\n"
    "2:\n"
    "lui $14,0x36\n"
    "ld $31,0($29)\n"
    "lw $15,-4972($14)\n"
    "addu $15,$12,$15\n"
    "ldl $10,15($13)\n"
    "ldr $10,8($13)\n"
    "sdl $10,39($15)\n"
    "sdr $10,32($15)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_00241850, .-func_00241850\n"
    ".text\n"
);
