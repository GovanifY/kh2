#include "../common/types.h"

// FUN_001bc050 (64 bytes)
// Code: calls the mangled MISSION::IsExec helper at 0x1bb4a0; if it returns zero the result is
// 0. Otherwise calls FUN_001bbcb0, which returns a pointer; the halfword at +8 -> +4 has bit 14
// tested and returned as 0 or 1.
// Build: whole-body asm (form a) with numeric jal targets. The move-zero sits in the beqz delay
// slot, which keeps the .o identical.
void func_001bc050(void) __attribute__((noreturn));
void func_001bc050(void) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $31,0($29)\n\t"
        "jal 0x1bb4a0\n\t"
        "nop\n\t"
        "beqz $2,1f\n\t"
        "daddu $15,$0,$0\n\t"
        "jal 0x1bbcb0\n\t"
        "nop\n\t"
        "lw $14,8($2)\n\t"
        "lhu $15,4($14)\n\t"
        "srl $15,$15,14\n\t"
        "andi $15,$15,1\n\t"
        "1:\n\t"
        "ld $31,0($29)\n\t"
        "daddu $2,$15,$0\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder"
        : : : "memory");
}
