#include "../common/types.h"

// FUN_001dcb98 (104 bytes). Fills a 4-float stack array: element i = (float)byte[a1 + i] * the float
// at 0x370000 - 6168. Calls FUN_001dc670(array); if the result is not sp, copies the 16-byte array
// to the result. Returns with the frame of 32 bytes.
// Matching: whole-body file-scope asm (form b). The loop is written with raw addu/lbu/mtc1 so the
// byte order and the delay-slot addiu t4 stay as in the original.
void r_FUN_001dcb98(void) asm("func_001dcb98");
#if 0
void r_FUN_001dcb98(void) {
}
#endif

__asm__(
    ".section .text.func_001dcb98,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001dcb98\n"
    ".type func_001dcb98, @function\n"
    "func_001dcb98:\n"
    "addiu $29,$29,-32\n"
    "lui $15,0x37\n"
    "sd $31,16($29)\n"
    "addiu $15,$15,-6168\n"
    "daddu $13,$0,$0\n"
    "daddu $12,$29,$0\n"
    "lwc1 $f1,0($15)\n"
    "1:\n"
    "addu $15,$5,$13\n"
    "lbu $14,0($15)\n"
    "addiu $13,$13,1\n"
    "mtc1 $14,$f0\n"
    "slti $15,$13,4\n"
    "cvt.s.w $f0,$f0\n"
    "mul.s $f0,$f0,$f1\n"
    "swc1 $f0,0($12)\n"
    "bnez $15,1b\n"
    "addiu $12,$12,4\n"
    "jal 0x1dc670\n"
    "nop\n"
    "beq $2,$29,2f\n"
    "ld $31,16($29)\n"
    "lq $8,0($29)\n"
    "sq $8,0($2)\n"
    "ld $31,16($29)\n"
    "2:\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_001dcb98, .-func_001dcb98\n"
    ".text\n");
