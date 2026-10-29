#include "../common/types.h"

// Agent R46p_40 (2026-10-29): FUN_001b8988 (72 bytes), SLPM_666.75.
// Code: frame of 16 bytes. Stores the low byte of a1 at 0x1d5 0x0000 - 29292 (lui t7 + sb).
// If the word at a0+12 is zero, returns. Otherwise tail-calls the callee at 0x1db610 with
// (word at 0x1d5 0x0000 - 29296 + t6, 0x1c0000 - 30256, 0). The ld ra sits in the beqz delay slot.
// Matching: whole-body noreorder asm, because gcc will not place the ld ra in the beqz delay slot
// in this order.
void func_001b8988(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "andi $5,$5,0xff\n\t"
        "lui $15,0x1d5\n\t"
        "sd $31,0($29)\n\t"
        "sb $5,-29292($15)\n\t"
        "lw $14,12($4)\n\t"
        "beqz $14,1f\n\t"
        " ld $31,0($29)\n\t"
        "lui $15,0x1d5\n\t"
        "lw $4,-29296($15)\n\t"
        "lui $5,0x1c\n\t"
        "addiu $5,$5,-30256\n\t"
        "daddu $6,$0,$0\n\t"
        "addu $4,$4,$14\n\t"
        "j 0x1db610\n\t"
        " addiu $29,$29,16\n\t"
        "1:\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
