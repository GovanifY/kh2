#include "../common/types.h"

// FUN_001bc0e0 (76 bytes)
// Code: s0 = 0; calls the mangled MISSION::IsExec helper at 0x1bb4a0. If it returns zero, branch-likely
// returns 0 (li s0,1 only runs when the branch is not taken). Otherwise calls FUN_001bbcb0 and
// tests bit 0x10 of the halfword/word at +4 of its result; returns 1 when the bit is set, else 0.
// Build: whole-body asm (form a). gcc 3.2 does not emit the beqzl branch-likely, so the body is
// asm with numeric jal targets. Needs -falign-functions=1 (76 is not a multiple of 8).
void func_001bc0e0(void) __attribute__((noreturn));
void func_001bc0e0(void) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "jal 0x1bb4a0\n\t"
        "daddu $16,$0,$0\n\t"
        "beqzl $2,1f\n\t"
        "li $16,1\n\t"
        "jal 0x1bbcb0\n\t"
        "nop\n\t"
        "lw $15,4($2)\n\t"
        "andi $15,$15,0x10\n\t"
        "bnez $15,2f\n\t"
        "daddu $2,$16,$0\n\t"
        "li $16,1\n\t"
        "1:\n\t"
        "daddu $2,$16,$0\n\t"
        "2:\n\t"
        "ld $31,8($29)\n\t"
        "ld $16,0($29)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder"
        : : : "memory");
}
