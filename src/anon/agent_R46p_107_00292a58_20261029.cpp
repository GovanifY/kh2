// Agent R46p_107 (2026-10-29): FUN_00292a58 (56 bytes), SLPM_666.75.
// Code: frame of 16 bytes. Clears the halfword at 0x360000 - 2856, then calls the function at 0x2fde18
// with a1 = 0, a2 = (word at 0x360000 - 2884) << 4, a0 = word at 0x360000 - 2860. Tail-jumps to 0x292998.
// Matching: whole-function file-scope __asm__ block with numeric jal/j targets; the tail j's addiu sits in its delay slot.
void r_FUN_00292a58(void) asm("func_00292a58");
#if 0
void r_FUN_00292a58(void) {
}
#endif

__asm__(
    ".section .text.func_00292a58,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00292a58\n"
    ".type func_00292a58, @function\n"
    "func_00292a58:\n"
    "addiu $29,$29,-16\n"
    "lui $15,0x36\n"
    "sd $31,0($29)\n"
    "lui $14,0x36\n"
    "sh $0,-2856($14)\n"
    "daddu $5,$0,$0\n"
    "lw $6,-2884($15)\n"
    "lui $15,0x36\n"
    "sll $6,$6,4\n"
    "jal 0x2fde18\n"
    "lw $4,-2860($15)\n"
    "ld $31,0($29)\n"
    "j 0x292998\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_00292a58, .-func_00292a58\n"
    ".text\n");
