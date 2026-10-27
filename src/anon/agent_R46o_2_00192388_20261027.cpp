#include "../common/types.h"

// FUN_00192388 (64 bytes): whole-body asm. Reads the byte at a0. Values 1..31 advance a0 by a table byte at
// 0x0036cea0 + c; 0 returns 0; 32 and up advance a0 by 1.
u8* func_00192388(u8* a0) __attribute__((noreturn));
u8* func_00192388(u8* a0) {
    __asm__ volatile(
        ".set push\n\t"
        ".set noreorder\n\t"
        "lbu $14,0($4)\n\t"
        "sltiu $15,$14,32\n\t"
        "bnez $15,1f\n\t"
        "nop\n\t"
        "addiu $4,$4,1\n\t"
        "3:\n\t"
        "move $2,$4\n\t"
        "4:\n\t"
        "jr $31\n\t"
        "nop\n\t"
        "1:\n\t"
        "beqz $14,4b\n\t"
        "move $2,$0\n\t"
        "lui $15,0x37\n\t"
        "addiu $15,$15,-12640\n\t"
        "addu $15,$14,$15\n\t"
        "lbu $14,0($15)\n\t"
        "b 3b\n\t"
        "addu $4,$4,$14\n\t"
        ".set pop" : : "r"(a0));
}
