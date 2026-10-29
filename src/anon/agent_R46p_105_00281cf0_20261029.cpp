#include "../common/types.h"

// func_00281cf0 (72 bytes)
// Stores a zero byte at 0x0035F298, saves a0 in s0, loads a float constant from 0x003741A4,
// stores it at 0x0035F294, calls func_00281b30 (Tz::CmItem::FadeOutHelp), then stores s0 as a halfword at 0x0035F280.
// Whole-body asm: the sd/ld order and the lui/sb/swc1/sh interleave are reproduced exactly.
void func_00281cf0(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "lui $15,0x37\n\t"
        "sd $16,0($29)\n\t"
        "addiu $15,$15,16804\n\t"
        "sd $31,8($29)\n\t"
        "lui $14,0x36\n\t"
        "sb $0,-3432($14)\n\t"
        "daddu $16,$4,$0\n\t"
        "lwc1 $f0,0($15)\n\t"
        "lui $15,0x36\n\t"
        "jal 0x281b30\n\t"
        " swc1 $f0,-3436($15)\n\t"
        "lui $15,0x36\n\t"
        "ld $31,8($29)\n\t"
        "sh $16,-3456($15)\n\t"
        "ld $16,0($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
