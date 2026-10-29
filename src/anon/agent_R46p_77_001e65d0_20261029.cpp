#include "../common/types.h"

// Agent R46p_77 (2026-10-29): FUN_001e65d0 (96 bytes), SLPM_666.75.
// Code: frame of 16 bytes; saves ra and s0. Calls 0x1e5990(0x350000 + 18072), 0x1e5610(word at s0 + 17992
// with s0 = 0x350000), 0x1e5898(same word), 0x2f25a0(0, 0), 0x3058a0(0), then reloads ra and s0
// and tail-jumps to 0x2f3918 with a0 = word at 0x360000 - 28216 and a1 = 0x350000 + 18000.
// Matching: whole-function file-scope __asm__ (form b). The ld ra sits between the a1 and j, so plain C
// does not match the epilogue placement. Callees are reached by numeric jal/j.
void r_FUN_001e65d0(void) asm("func_001e65d0");
#if 0
void r_FUN_001e65d0(void) {
}
#endif

__asm__(
    ".section .text.func_001e65d0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001e65d0\n"
    ".type func_001e65d0, @function\n"
    "func_001e65d0:\n"
    "addiu $29,$29,-16\n"
    "lui $4,0x35\n"
    "sd $31,8($29)\n"
    "sd $16,0($29)\n"
    "jal 0x1e5990\n"
    "addiu $4,$4,18072\n"
    "lui $16,0x35\n"
    "jal 0x1e5610\n"
    "lw $4,17992($16)\n"
    "jal 0x1e5898\n"
    "lw $4,17992($16)\n"
    "daddu $5,$0,$0\n"
    "jal 0x2f25a0\n"
    "daddu $4,$0,$0\n"
    "jal 0x3058a0\n"
    "daddu $4,$0,$0\n"
    "lui $15,0x36\n"
    "ld $16,0($29)\n"
    "lw $4,-28216($15)\n"
    "lui $5,0x35\n"
    "ld $31,8($29)\n"
    "addiu $5,$5,18000\n"
    "j 0x2f3918\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001e65d0, .-func_001e65d0\n"
    ".text\n");
