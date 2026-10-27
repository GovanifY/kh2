#include "../common/types.h"

extern u32 D_00354690[];
extern "C" void func_001e60b0(void);

// FUN_001e6250 (48 bytes): whole-body asm. Saves ra, calls FUN_001e60b0(), zeroes the word at
// D_00354690 and stores -1 at D_00354690+4, then restores ra and returns. The ld ra sits between the
// lui and addiu, which the C forms did not reproduce. gcc appends a dead jr ra after the 48 bytes.
void func_001e6250(void) __attribute__((noreturn));
void func_001e6250(void) {
    __asm__ volatile(
        ".set push\n\t"
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $31,0($29)\n\t"
        "jal func_001e60b0\n\t"
        "nop\n\t"
        "lui $15,%hi(D_00354690)\n\t"
        "ld $31,0($29)\n\t"
        "addiu $13,$15,%lo(D_00354690)\n\t"
        "sw $0,%lo(D_00354690)($15)\n\t"
        "li $14,-1\n\t"
        "sw $14,4($13)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set pop");
}
