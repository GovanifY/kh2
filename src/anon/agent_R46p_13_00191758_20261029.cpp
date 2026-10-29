#include "../common/types.h"

// Agent R46p_13 (2026-10-29): FUN_00191758 (88 bytes, SLPM_666.75).
// Code: frame of 16. Stores 0 at 0x34f240 in the jal 0x191938 delay slot (a0 = 0). Then restores
// ra, loads the float at 0x36cd58 into f1, stores 0 at 0x1c61960, loads the float at 0x36cd5c
// into f0, stores f0 at 0x1c6195c and f1 at 0x1c61964, and tail-calls 0x191bf0 with f1 in f12.
// Matching: whole-body asm (form b). Plain C gives the same stores and loads, but gcc keeps
// the ld ra at the tail instead of right after the call, so the epilogue order differs. The
// asm uses numeric jal/j targets and literal immediates.

void r_FUN_00191758(void) asm("func_00191758");
#if 0
void r_FUN_00191758(void) {
}
#endif

__asm__(
    ".section .text.func_00191758,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00191758\n"
    ".type func_00191758, @function\n"
    "func_00191758:\n"
    "addiu $29,$29,-16\n"
    "lui $15,0x35\n"
    "sd $31,0($29)\n"
    "daddu $4,$0,$0\n"
    "jal 0x191938\n"
    "sw $0,-3520($15)\n"
    "lui $15,0x37\n"
    "ld $31,0($29)\n"
    "addiu $15,$15,-12968\n"
    "lui $14,0x1c6\n"
    "lwc1 $f1,0($15)\n"
    "sw $0,6496($14)\n"
    "lui $15,0x37\n"
    "mov.s $f12,$f1\n"
    "addiu $15,$15,-12964\n"
    "lwc1 $f0,0($15)\n"
    "lui $15,0x1c6\n"
    "swc1 $f0,6492($15)\n"
    "lui $15,0x1c6\n"
    "swc1 $f1,6500($15)\n"
    "j 0x191bf0\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_00191758, .-func_00191758\n"
    ".text\n");
