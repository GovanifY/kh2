#include "../common/types.h"

// Agent R46p_98 (2026-10-29): FUN_0024b1a0 (84 bytes), SLPM_666.75.
// Whole-body asm: if a0 == 1 and func_0024ac88(a0) != 0, returns 0x371EB8; otherwise
// returns 0x371EA8 + a0 * 6 (R5900 3-operand mult, raw .word 0x020f7818 = mult $15,$16,$15).
// The prologue (addiu sp, sd s0, sd ra) and the epilogue are in the asm, in the original order.
void func_0024b1a0(void) {
    asm volatile(
        ".set push\n"
        ".set noreorder\n"
        "addiu $29,$29,-16\n"
        "addiu $15,$0,1\n"
        "sd $16,0($29)\n"
        "sd $31,8($29)\n"
        "bne $4,$15,3f\n"
        "daddu $16,$4,$0\n"
        "jal 0x24ac88\n"
        "nop\n"
        "beqz $2,3f\n"
        "lui $15,0x37\n"
        "addiu $2,$15,7864\n"
        "5:\n"
        "ld $16,0($29)\n"
        "ld $31,8($29)\n"
        "jr $31\n"
        "addiu $29,$29,16\n"
        "3:\n"
        "addiu $15,$0,6\n"
        "lui $14,0x37\n"
        ".word 0x020f7818\n"
        "addiu $14,$14,7848\n"
        "b 5b\n"
        "addu $2,$15,$14\n"
        ".set pop\n" ::: "memory");
}
