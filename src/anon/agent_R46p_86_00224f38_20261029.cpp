// Agent R46p_86 (2026-10-29): FUN_00224f38 (104 bytes), SLPM_666.75.
// Creates a task via FIELD::CreateTask (0x102c18), stores the result at *a1, stores 0x224f08 at task+48,
// calls func_0022a368(a3) and stores its result at *a2. Plain C gives the same body, but gcc's prologue
// order and jal delay-slot choices differ, so the whole body is one top-level asm block (form b).
void r_FUN_00224f38(void) asm("func_00224f38");
#if 0
void r_FUN_00224f38(void) {
}
#endif

__asm__(
    ".section .text.func_00224f38,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00224f38\n"
    ".type func_00224f38, @function\n"
    "func_00224f38:\n"
    "addiu $29,$29,-32\n"
    "sd $17,8($29)\n"
    "sd $18,16($29)\n"
    "sd $16,0($29)\n"
    "daddu $17,$5,$0\n"
    "daddu $18,$6,$0\n"
    "sd $31,24($29)\n"
    "daddu $5,$4,$0\n"
    "lui $6,0x23\n"
    "daddu $16,$7,$0\n"
    "addiu $6,$6,-20216\n"
    "jal 0x102c18\n"
    "addiu $4,$0,1\n"
    "sw $2,0($17)\n"
    "lui $15,0x22\n"
    "addiu $15,$15,20232\n"
    "daddu $4,$16,$0\n"
    "jal 0x22a368\n"
    "sw $15,48($2)\n"
    "sw $2,0($18)\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $18,16($29)\n"
    "ld $31,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_00224f38, .-func_00224f38\n"
    ".text\n");
