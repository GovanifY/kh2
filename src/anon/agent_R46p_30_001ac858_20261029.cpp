#include "../common/types.h"

// Agent R46p_30 (2026-10-29): FUN_001ac858 (88 bytes), SLPM_666.75.
// Stores a0 as s0, calls func_001ac378(a0, 4, 3, a1, 0, 256, 365), then writes
// 4 to +100 and the vtable word 0x350000 + 3056 to +0, and tail-calls func_001aa668(s0 + 12, s0).
// Whole-body asm (form b): the callee 0x1ac378 has no functions.tsv row, so it is a numeric jal.
void r_FUN_001ac858(void) asm("func_001ac858");
#if 0
void r_FUN_001ac858(void) {
}
#endif

__asm__(
    ".section .text.func_001ac858,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001ac858\n"
    ".type func_001ac858, @function\n"
    "func_001ac858:\n"
    "addiu $29,$29,-16\n"
    "daddu $7,$5,$0\n"
    "sd $16,0($29)\n"
    "addiu $5,$0,4\n"
    "sd $31,8($29)\n"
    "addiu $6,$0,3\n"
    "daddu $16,$4,$0\n"
    "daddu $8,$0,$0\n"
    "addiu $9,$0,256\n"
    "jal 0x1ac378\n"
    "addiu $10,$0,365\n"
    "lui $15,0x35\n"
    "ld $31,8($29)\n"
    "addiu $14,$0,4\n"
    "addiu $15,$15,3056\n"
    "sw $14,100($16)\n"
    "addiu $4,$16,12\n"
    "sw $15,0($16)\n"
    "daddu $5,$16,$0\n"
    "ld $16,0($29)\n"
    "j 0x1aa668\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001ac858, .-func_001ac858\n"
    ".text\n");
