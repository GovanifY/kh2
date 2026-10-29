// Agent R46p_93 (2026-10-29): FUN_0023ef50 (100 bytes), SLPM_666.75.
// Whole-body asm (form b). Plain C gave the right loop but the wrong delay-slot fill for blez
// (move s0,zero must sit in the blez delay slot) and a swapped s1/s2 assignment, so the body is
// written out with the reference opcodes and numeric jal 0x236ca8 (IMAGE_FREEZE::GetImage).
void r_FUN_0023ef50(void) asm("func_0023ef50");
#if 0
void r_FUN_0023ef50(void) {
}
#endif

__asm__(
    ".section .text.func_0023ef50,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0023ef50\n"
    ".type func_0023ef50, @function\n"
    "func_0023ef50:\n"
    "addiu $29,$29,-48\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $18,16($29)\n"
    "sd $19,24($29)\n"
    "sd $31,32($29)\n"
    "lw $17,40($4)\n"
    "blez $17,2f\n"
    "daddu $16,$0,$0\n"
    "addiu $18,$4,48\n"
    "addiu $19,$0,1\n"
    "1:\n"
    "lw $4,40($18)\n"
    "daddu $5,$16,$0\n"
    "jal 0x236ca8\n"
    "addiu $16,$16,1\n"
    "slt $15,$16,$17\n"
    "bne $15,$0,1b\n"
    "sb $19,400($2)\n"
    "2:\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $18,16($29)\n"
    "ld $19,24($29)\n"
    "ld $31,32($29)\n"
    "jr $31\n"
    "addiu $29,$29,48\n"
    ".set pop\n"
    ".size func_0023ef50, .-func_0023ef50\n"
    ".text\n"
);
