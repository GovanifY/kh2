#include "../common/types.h"

// Agent R46p_24 (2026-10-29): FUN_001a6b58 (108 bytes), SLPM_666.75.
// Code: frame of 16 bytes. Saves s0 then ra, s0 = a0, calls the PIERRO ctor (001b3b70, mangled row)
// as (self, a1, 4, a2), then sets bits on self+1536 (clear 0x78, set 0x8), self+1416 (0x100),
// self+2748 (0x4), writes the vtable word 0x350910 at self+0 and 3 at self+944.
// Matching: plain C gave a different register allocation and store order, so this is form (b):
// file-scope __asm__ whole body with a numeric jal to the callee. The asm carries the exact words.
void r_FUN_001a6b58(void) asm("func_001a6b58");
#if 0
void r_FUN_001a6b58(void) {
}
#endif

__asm__(
    ".section .text.func_001a6b58,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001a6b58\n"
    ".type func_001a6b58, @function\n"
    "func_001a6b58:\n"
    "addiu $29,$29,-16\n"
    "daddu $7,$6,$0\n"
    "sd $16,0($29)\n"
    "addiu $6,$0,4\n"
    "sd $31,8($29)\n"
    "jal 0x1b3b70\n"
    "daddu $16,$4,$0\n"
    "lw $13,1536($16)\n"
    "addiu $15,$0,-121\n"
    "lw $12,1416($16)\n"
    "and $13,$13,$15\n"
    "lw $14,2748($16)\n"
    "lui $15,0x35\n"
    "ld $31,8($29)\n"
    "addiu $15,$15,2320\n"
    "ori $12,$12,0x100\n"
    "sw $15,0($16)\n"
    "ori $14,$14,0x4\n"
    "ori $13,$13,0x8\n"
    "sw $14,2748($16)\n"
    "addiu $15,$0,3\n"
    "sw $12,1416($16)\n"
    "sw $15,944($16)\n"
    "sw $13,1536($16)\n"
    "ld $16,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001a6b58, .-func_001a6b58\n"
    ".text\n");
