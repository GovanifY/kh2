// Agent R46p_107 (2026-10-29): FUN_0028b078 (100 bytes), SLPM_666.75.
// Code: frame of 16 bytes. Clears the byte at a0+38, stores a1 and a2 as halfwords at a0+24 and a0+26,
// sets the byte at a0+37 to 1, calls 0x288f48(a0, 16, 32, 64, 128) and 0x28af18(a0, 127), then tail-jumps
// to 0x28b1b0 with a1 = 0.
// Matching: whole-function file-scope __asm__ block with numeric jal/j targets and the original store order.
void r_FUN_0028b078(void) asm("func_0028b078");
#if 0
void r_FUN_0028b078(void) {
}
#endif

__asm__(
    ".section .text.func_0028b078,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0028b078\n"
    ".type func_0028b078, @function\n"
    "func_0028b078:\n"
    "addiu $29,$29,-16\n"
    "sb $0,38($4)\n"
    "daddu $14,$5,$0\n"
    "sd $16,0($29)\n"
    "daddu $13,$6,$0\n"
    "sd $31,8($29)\n"
    "addiu $15,$0,1\n"
    "sh $14,24($4)\n"
    "sb $15,37($4)\n"
    "daddu $16,$4,$0\n"
    "sh $13,26($4)\n"
    "addiu $6,$0,32\n"
    "addiu $7,$0,64\n"
    "addiu $8,$0,128\n"
    "jal 0x288f48\n"
    "addiu $5,$0,16\n"
    "daddu $4,$16,$0\n"
    "jal 0x28af18\n"
    "addiu $5,$0,127\n"
    "daddu $4,$16,$0\n"
    "ld $31,8($29)\n"
    "ld $16,0($29)\n"
    "daddu $5,$0,$0\n"
    "j 0x28b1b0\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_0028b078, .-func_0028b078\n"
    ".text\n");
