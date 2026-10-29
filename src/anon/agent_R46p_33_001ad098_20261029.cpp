#include "../common/types.h"

// Agent R46p_33 (2026-10-29): func_001ad098 (92 bytes), SLPM_666.75.
// Calls func_001ac970(p, 3, 5, a1, a2, 128, 104, 0) with the arguments in a0-a3 and t0-t3, then stores
// the float at 0x36d79c into +104 and 0x350b70 into *p. The ra restore sits between the call and the
// stores, so the epilogue interleaves with the body. Plain C does not match, so this is form (b):
// whole-body asm. The jal target is numeric (001ac970 has no functions.tsv row).
void r_FUN_001ad098(void) asm("func_001ad098");
#if 0
void r_FUN_001ad098(void) {
}
#endif

asm(
    ".section .text.func_001ad098,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001ad098\n"
    ".type func_001ad098, @function\n"
    "func_001ad098:\n"
    "addiu $29,$29,-16\n"
    "daddu $7,$5,$0\n"
    "sd $16,0($29)\n"
    "daddu $8,$6,$0\n"
    "sd $31,8($29)\n"
    "addiu $5,$0,3\n"
    "daddu $16,$4,$0\n"
    "addiu $6,$0,5\n"
    "addiu $9,$0,128\n"
    "addiu $10,$0,104\n"
    "jal 0x1ac970\n"
    "daddu $11,$0,$0\n"
    "lui $15,0x37\n"
    "ld $31,8($29)\n"
    "addiu $15,$15,-10340\n"
    "lwc1 $f0,0($15)\n"
    "lui $15,0x35\n"
    "swc1 $f0,104($16)\n"
    "addiu $15,$15,2928\n"
    "sw $15,0($16)\n"
    "ld $16,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001ad098, .-func_001ad098\n"
    ".text\n");
