#include "../common/types.h"

// Agent R46p_1 (2026-10-29): FUN_00176620 (92 bytes), SLPM_666.75.
// Sets bit 0x2000000 in the word at +264 of arg0, calls func_00177a58(arg0), then tail-calls
// func_00187018(arg0, arg1, 0, -1) with the float at D_00370000-15184 in $f12.
// Matching: plain C gives the right instructions but gcc keeps the epilogue loads (ld ra, ld s0,
// ld s1) in a different order and appends its own jr ra. The whole body is one file-scope asm
// block, so the restores and the tail jump are in the original order.
void r_FUN_00176620(void) asm("func_00176620");
#if 0
void r_FUN_00176620(void) {
}
#endif

__asm__(
    ".section .text.func_00176620,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00176620\n"
    ".type func_00176620, @function\n"
    "func_00176620:\n"
    "addiu $29,$29,-32\n"
    "lui $14,0x200\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $31,16($29)\n"
    "daddu $16,$4,$0\n"
    "daddu $17,$5,$0\n"
    "lw $15,264($4)\n"
    "or $15,$15,$14\n"
    "jal func_00177a58\n"
    "sw $15,264($4)\n"
    "lui $15,0x37\n"
    "ld $31,16($29)\n"
    "daddu $4,$16,$0\n"
    "daddu $5,$17,$0\n"
    "addiu $15,$15,-15184\n"
    "ld $16,0($29)\n"
    "lwc1 $f12,0($15)\n"
    "daddu $6,$0,$0\n"
    "ld $17,8($29)\n"
    "addiu $7,$0,-1\n"
    "j func_00187018\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_00176620, .-func_00176620\n"
    ".text\n");
