#include "../common/types.h"

// Agent R46p_53 (2026-10-29): func_001ce3e8 (108 bytes), SLPM_666.75.
// Saves a1 in s1 and a0 in s0, calls func_001980d0(a0, a2, 4), stores s1 at +2548 of the object,
// writes the vtable word 0x352140 at +0, calls func_001dba88(s1), sets bit 0x800000 in the word at
// +1416, and stores 0x1d5b9e0 at +2552.
// Callee 001980d0 has no functions.tsv row, so plain C would call through a pointer. This is form (b):
// whole-body asm with numeric jal targets, copied from the reference disassembly.
void r_FUN_001ce3e8(void) asm("func_001ce3e8");
#if 0
void r_FUN_001ce3e8(void) {
}
#endif

__asm__(
    ".section .text.func_001ce3e8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001ce3e8\n"
    ".type func_001ce3e8, @function\n"
    "func_001ce3e8:\n"
    "addiu $29,$29,-32\n"
    "sd $17,8($29)\n"
    "sd $16,0($29)\n"
    "daddu $17,$5,$0\n"
    "sd $31,16($29)\n"
    "daddu $5,$6,$0\n"
    "daddu $16,$4,$0\n"
    "jal 0x1980d0\n"
    "addiu $6,$0,4\n"
    "lui $15,0x35\n"
    "sw $17,2548($16)\n"
    "addiu $15,$15,8512\n"
    "daddu $4,$17,$0\n"
    "jal 0x1dba88\n"
    "sw $15,0($16)\n"
    "lw $13,1416($16)\n"
    "lui $14,0x80\n"
    "lui $15,0x1d6\n"
    "ld $17,8($29)\n"
    "or $13,$13,$14\n"
    "ld $31,16($29)\n"
    "addiu $15,$15,-17952\n"
    "sw $13,1416($16)\n"
    "sw $15,2552($16)\n"
    "ld $16,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_001ce3e8, .-func_001ce3e8\n"
    ".text\n");
