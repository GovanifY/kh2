#include "../common/types.h"

// FUN_001bb7f8 (92 bytes)
// Code: s0 = 0; calls the mangled YS::MISSION::IsExec helper at 0x1bb4a0 and returns s0 if
// it is zero. Otherwise calls FUN_00198d00(8, -1); a non-zero result gives 1. Otherwise it
// loads the word at (0x1d5 << 16) - 27872, then the word at +172 of that pointer, and returns
// 1 if it is non-zero, else 0. The bnezl and beqz branches come from the original.
// Build: whole-body asm (form a). The branch-likely (bnezl) is not emitted by gcc 3.2.
// Numeric jal targets keep the .o identical; the first call has no named symbol.
void func_001bb7f8(void) __attribute__((noreturn));
void func_001bb7f8(void) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "jal 0x1bb4a0\n\t"
        "daddu $16,$0,$0\n\t"
        "li $4,8\n\t"
        "beqz $2,1f\n\t"
        "li $5,-1\n\t"
        "jal 0x198d00\n\t"
        "nop\n\t"
        "bnezl $2,1f\n\t"
        "li $16,1\n\t"
        "lui $15,0x1d5\n\t"
        "lw $14,-27872($15)\n\t"
        "lw $13,172($14)\n\t"
        "beqz $13,2f\n\t"
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
