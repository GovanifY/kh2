#include "../common/types.h"

// FUN_001be900 (64 bytes), whole-body asm.
// Code: s0 = a0, s1 = a0 + 152, s0 += 2628; calls YS::COMMAND_MENU::clear(s1) (0x1bc778) with the
// a0 move repeated after the call; then tail-jumps to func_001bc990(s1, s0) (0x1bc990).
// Plain C computed s0 = a0 + 2628 first, which gave a different instruction order.
void func_001be900(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "sd $16,0($29)\n\t"
        "sd $17,8($29)\n\t"
        "sd $31,16($29)\n\t"
        "daddu $16,$4,$0\n\t"
        "addiu $17,$4,152\n\t"
        "addiu $16,$16,2628\n\t"
        "jal 0x1bc778\n\t"
        "daddu $4,$17,$0\n\t"
        "daddu $4,$17,$0\n\t"
        "ld $31,16($29)\n\t"
        "daddu $5,$16,$0\n\t"
        "ld $17,8($29)\n\t"
        "ld $16,0($29)\n\t"
        "j 0x1bc990\n\t"
        "addiu $29,$29,32\n\t"
        ".set reorder"
        ::: "memory");
}
