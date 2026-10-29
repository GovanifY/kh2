#include "../common/types.h"

// Agent R46p_33 (2026-10-29): func_001aea00 (96 bytes), SLPM_666.75.
// Calls func_00185b00(p) with the object pointer, then stores 0x350ce0 at *p, sets bit 0x400 in the word
// at +1416, zeroes the word at +1912, stores the float at 0x36d85c into +1908, and sets bits 0x8404 in the
// word at +2748. The ra restore sits in the middle of the body, so the epilogue interleaves with the stores.
// Plain C gave a different store order and a different epilogue, so this is form (b): whole-body asm with
// the original sequence. The jal target is numeric.
void r_FUN_001aea00(void) asm("func_001aea00");
#if 0
void r_FUN_001aea00(void) {
}
#endif

asm(
    ".section .text.func_001aea00,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001aea00\n"
    ".type func_001aea00, @function\n"
    "func_001aea00:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "jal 0x185b00\n"
    "daddu $16,$4,$0\n"
    "lui $15,0x35\n"
    "lw $14,1416($16)\n"
    "addiu $15,$15,3296\n"
    "ld $31,8($29)\n"
    "sw $15,0($16)\n"
    "ori $14,$14,0x400\n"
    "sw $14,1416($16)\n"
    "addiu $13,$16,1648\n"
    "lui $15,0x37\n"
    "addiu $15,$15,-10148\n"
    "sw $0,264($13)\n"
    "lwc1 $f0,0($15)\n"
    "swc1 $f0,260($13)\n"
    "lw $15,2748($16)\n"
    "ori $15,$15,0x8404\n"
    "sw $15,2748($16)\n"
    "ld $16,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001aea00, .-func_001aea00\n"
    ".text\n");
