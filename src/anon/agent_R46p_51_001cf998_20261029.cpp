#include "../common/types.h"

// FUN_001cf998 (68 bytes).
// Code: s0 = 0. Calls YS::MISSION::IsExec (mangled, 0x1bb4a0); if it returns 0, s0 = 1 and returns 1.
// Otherwise calls YS::MISSION::GetCount(1) (mangled, 0x1d87b8); returns 0 if it is <= 0, else s0 (1).
// Build: whole-body asm (form a). Plain C gives a slt for the return value. Numeric jal targets.
void func_001cf998(void) __attribute__((noreturn));
void func_001cf998(void) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "jal 0x1bb4a0\n\t"
        "daddu $16,$0,$0\n\t"
        "beqz $2,1f\n\t"
        "li $4,1\n\t"
        "jal 0x1d87b8\n\t"
        "nop\n\t"
        "blez $2,2f\n\t"
        "daddu $2,$16,$0\n\t"
        "1:\n\t"
        "li $16,1\n\t"
        "daddu $2,$16,$0\n\t"
        "2:\n\t"
        "ld $31,8($29)\n\t"
        "ld $16,0($29)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder"
        : : : "memory");
}
