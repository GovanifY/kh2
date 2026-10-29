#include "../common/types.h"

// Agent R46p_36 (2026-10-29): FUN_001b4300 (60 bytes, SLPM_666.75).
// Clears the word at 0x01d48cb0, calls 0x102c18 with (1, 20600, 0x1b4340), then stores 0x1b43e0 at +48
// of the returned pointer. Plain C gives the wrong scheduling (sd ra, lui a2, sw order), so this is
// whole-body asm: the numeric jal keeps the object free of callee reloc names.
void func_001b4300(void) asm("func_001b4300");
#if 0
void func_001b4300(void) {
}
#endif

__asm__(
    ".section .text.func_001b4300,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001b4300\n"
    ".type func_001b4300, @function\n"
    "func_001b4300:\n"
    "addiu $29,$29,-16\n"
    "lui $15,0x1d5\n"
    "sd $31,0($29)\n"
    "lui $6,0x1b\n"
    "sw $0,-29520($15)\n"
    "addiu $6,$6,17216\n"
    "addiu $4,$0,1\n"
    "jal 0x102c18\n"
    "addiu $5,$0,20600\n"
    "lui $15,0x1b\n"
    "ld $31,0($29)\n"
    "addiu $15,$15,17376\n"
    "sw $15,48($2)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001b4300, .-func_001b4300\n"
    ".text\n");
