#include "../common/types.h"

// Agent R46p_77 (2026-10-29): FUN_001e41e0 (104 bytes), SLPM_666.75.
// Code: frame of 16 bytes. Saves ra, then s0. v0 = word at a0+136; s0 = a0; calls
// func_001e3650(v0), func_001e3660(v0, 2), func_001e3c98(v0, [s0+140]+192),
// func_001e3e48(v0, [s0+140]+208), func_001e4028(v0, [s0+140]+224). No return value.
// Matching: whole-function file-scope __asm__ (form b). Plain C gives sd s0 before sd ra
// and calls unregistered callees through a pointer, so the words are taken from the reference.
// Callees without a functions.tsv row (001e3c98, 001e3e48, 001e4028) are reached by numeric jal.
void r_FUN_001e41e0(void) asm("func_001e41e0");
#if 0
void r_FUN_001e41e0(void) {
}
#endif

__asm__(
    ".section .text.func_001e41e0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001e41e0\n"
    ".type func_001e41e0, @function\n"
    "func_001e41e0:\n"
    "addiu $29,$29,-16\n"
    "sd $31,8($29)\n"
    "sd $16,0($29)\n"
    "lw $2,136($4)\n"
    "daddu $16,$4,$0\n"
    "jal 0x1e3650\n"
    "daddu $4,$2,$0\n"
    "daddu $4,$2,$0\n"
    "jal 0x1e3660\n"
    "addiu $5,$0,2\n"
    "lw $5,140($16)\n"
    "daddu $4,$2,$0\n"
    "jal 0x1e3c98\n"
    "addiu $5,$5,192\n"
    "lw $5,140($16)\n"
    "daddu $4,$2,$0\n"
    "jal 0x1e3e48\n"
    "addiu $5,$5,208\n"
    "lw $5,140($16)\n"
    "daddu $4,$2,$0\n"
    "jal 0x1e4028\n"
    "addiu $5,$5,224\n"
    "ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001e41e0, .-func_001e41e0\n"
    ".text\n");
