#include "../common/types.h"

// Agent R46p_84 (2026-10-29): FUN_00220c88 (104 bytes, SLPM_666.75).
// Saves ra/s0/s1, spills v0 to 0(sp), s0 = v0, s1 = v0+480, calls unnamed 0x2f3f88(s1, *(v0+500)),
// calls unnamed 0x222898(s0+160, s1, s0), then updates +500 (adds +516) and +524 (decrements).
// Matching: two unnamed callees with move delay slots and the v0 spill make plain C differ.
// Whole body is one file-scope asm block (form b) with numeric jal targets.
void r_FUN_00220c88(void) asm("func_00220c88");
#if 0
void r_FUN_00220c88(void) {
}
#endif

__asm__(
    ".section .text.func_00220c88,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00220c88\n"
    ".type func_00220c88, @function\n"
    "func_00220c88:\n"
    "addiu $29,$29,-48\n"
    "sd $31,32($29)\n"
    "sd $16,16($29)\n"
    "sd $17,24($29)\n"
    "sw $2,0($29)\n"
    "daddu $16,$2,$0\n"
    "addiu $17,$2,480\n"
    "lw $5,500($2)\n"
    "jal 0x2f3f88\n"
    "daddu $4,$17,$0\n"
    "addiu $4,$16,160\n"
    "daddu $6,$17,$0\n"
    "jal 0x222898\n"
    "daddu $5,$16,$0\n"
    "lw $14,500($16)\n"
    "lw $15,524($16)\n"
    "lw $13,516($16)\n"
    "addiu $15,$15,-1\n"
    "ld $17,24($29)\n"
    "addu $14,$14,$13\n"
    "sw $15,524($16)\n"
    "sw $14,500($16)\n"
    "ld $31,32($29)\n"
    "ld $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,48\n"
    ".set pop\n"
    ".size func_00220c88, .-func_00220c88\n"
    ".text\n");
