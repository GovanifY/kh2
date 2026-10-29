#include "../common/types.h"

// FUN_00178220 (96 bytes). Calls FUN_0019ee80(byte at 0x32bae0, byte at 0x32bae1), then copies the
// 10 bytes at 0x32bae0 to 0x32bb10 (ldl/ldr, lh, sdl/sdr, sh), then tail-calls FUN_001d5198(0x32bae0).
// The epilogue restores sit between the copy and the tail jump, which plain C does not reproduce,
// so this is a whole-body asm block with an #if 0 stub.
void r_FUN_00178220(void) asm("func_00178220");
#if 0
void r_FUN_00178220(void) {
}
#endif

__asm__(
    ".section .text.func_00178220,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00178220\n"
    ".type func_00178220, @function\n"
    "func_00178220:\n"
    "addiu $29,$29,-32\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $31,16($29)\n"
    "lui $16,0x33\n"
    "addiu $17,$16,-17696\n"
    "lbu $4,-17696($16)\n"
    "jal func_0019ee80\n"
    "lbu $5,1($17)\n"
    "lui $15,0x33\n"
    "ld $31,16($29)\n"
    "addiu $14,$16,-17696\n"
    "addiu $13,$15,-17648\n"
    "ldl $11,7($14)\n"
    "ldr $11,0($14)\n"
    "lh $12,8($14)\n"
    "sdl $11,7($13)\n"
    "sdr $11,0($13)\n"
    "sh $12,8($13)\n"
    "daddu $4,$17,$0\n"
    "ld $17,8($29)\n"
    "ld $16,0($29)\n"
    "j func_001d5198\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_00178220, .-func_00178220\n"
    ".text\n");
