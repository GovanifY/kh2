// Agent R46p_107 (2026-10-29): FUN_0028cc08 (52 bytes), SLPM_666.75.
// Code: frame of 16 bytes. a1 = a0; saves ra; a2 = ra; loads the object at the word at 0x360000 - 3080,
// then calls the vtable slot 0 through jalr v0 with a delay-slot nop.
// Matching: whole-function file-scope __asm__ block so gcc emits no prologue of its own.
void r_FUN_0028cc08(void) asm("func_0028cc08");
#if 0
void r_FUN_0028cc08(void) {
}
#endif

__asm__(
    ".section .text.func_0028cc08,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0028cc08\n"
    ".type func_0028cc08, @function\n"
    "func_0028cc08:\n"
    "addiu $29,$29,-16\n"
    "daddu $5,$4,$0\n"
    "sd $31,0($29)\n"
    "lui $15,0x36\n"
    "daddu $6,$31,$0\n"
    "lw $4,-3080($15)\n"
    "lw $15,0($4)\n"
    "lw $2,0($15)\n"
    "jalr $2\n"
    "nop\n"
    "ld $31,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_0028cc08, .-func_0028cc08\n"
    ".text\n");
