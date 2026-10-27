#include "../common/types.h"

// FUN_001979d8 (40 bytes): a1 = a0; a0 = word at D_00350000+892 plus 12; calls FUN_0019f2a8(a0, a1); returns.
// Whole body is one noreorder asm block (frame, delay-slot addiu and the ld ra/jr ra tail are as in the original).
extern "C" void func_0019f2a8(void);

void func_001979d8(u32 a0) __attribute__((noreturn));
void func_001979d8(u32 a0) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "daddu $5,$4,$0\n\t"
        "lui $15,0x35\n\t"
        "addiu $29,$29,-16\n\t"
        "lw $4,892($15)\n\t"
        "sd $31,0($29)\n\t"
        "jal func_0019f2a8\n\t"
        " addiu $4,$4,12\n\t"
        "ld $31,0($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
