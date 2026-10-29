#include "../common/types.h"

// FUN_001be940 (96 bytes), whole-body asm.
// Code: s0 = a0, s1 = a0 + 2642. Calls the unregistered FUN_001b9d40(*(a0 + 2528)) (numeric jal). If
// it returns non-zero, calls FUN_001d6da8(s1) (numeric jal). Then s0 += 848, calls
// YS::COMMAND_MENU::clear(s0) (0x1bc778), and tail-jumps to func_001bc990(s0, s1) (0x1bc990).
// Plain C cannot reach the unnamed callees with jal, and the delay-slot moves need the asm.
void func_001be940(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "sd $16,0($29)\n\t"
        "sd $17,8($29)\n\t"
        "sd $31,16($29)\n\t"
        "daddu $16,$4,$0\n\t"
        "addiu $17,$16,2642\n\t"
        "jal 0x1b9d40\n\t"
        "lw $4,2528($4)\n\t"
        "beqz $2,2f\n\t"
        "daddu $4,$17,$0\n\t"
        "jal 0x1d6da8\n\t"
        "nop\n\t"
        "1:\n\t"
        "addiu $16,$16,848\n\t"
        "jal 0x1bc778\n\t"
        "daddu $4,$16,$0\n\t"
        "daddu $4,$16,$0\n\t"
        "ld $31,16($29)\n\t"
        "daddu $5,$17,$0\n\t"
        "ld $16,0($29)\n\t"
        "ld $17,8($29)\n\t"
        "j 0x1bc990\n\t"
        "addiu $29,$29,32\n\t"
        "2:\n\t"
        "b 1b\n\t"
        "addiu $17,$16,2642\n\t"
        ".set reorder"
        ::: "memory");
}
