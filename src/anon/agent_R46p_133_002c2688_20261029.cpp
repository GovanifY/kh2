#include "../common/types.h"

// Agent R46p_133 (2026-10-29): func_002c2688 (108 bytes), SLPM_666.75.
// Whole-body noreorder asm: the C form did not reproduce the bnez/bnel layout. Calls
// func_001c3748(a0, v) in a loop, and returns 0 on a zero result. When the loop count reaches a1,
// it tail-returns func_001c3888(v) through a jal. Needs -falign-functions=1 (size 108).

void func_002c2688(u32 a0, u32 a1) __attribute__((noreturn));
void func_002c2688(u32 a0, u32 a1) {
    __asm__ volatile(
        ".set\tnoreorder\n\t"
        "addiu\t$29,$29,-32\n\t"
        "move\t$2,$0\n\t"
        "sd\t$16,0($29)\n\t"
        "sd\t$17,8($29)\n\t"
        "sd\t$18,16($29)\n\t"
        "move\t$16,$0\n\t"
        "sd\t$31,24($29)\n\t"
        "move\t$17,$5\n\t"
        "move\t$18,$4\n\t"
        "1:\n\t"
        "move\t$5,$2\n\t"
        "jal\t0x1c3748\n\t"
        "move\t$4,$18\n\t"
        "bnez\t$2,2f\n\t"
        "nop\n\t"
        "move\t$2,$0\n\t"
        "ld\t$16,0($29)\n\t"
        "4:\n\t"
        "ld\t$17,8($29)\n\t"
        "ld\t$18,16($29)\n\t"
        "ld\t$31,24($29)\n\t"
        "jr\t$31\n\t"
        "addiu\t$29,$29,32\n\t"
        "2:\n\t"
        "bnel\t$16,$17,1b\n\t"
        "addiu\t$16,$16,1\n\t"
        "jal\t0x1c3888\n\t"
        "move\t$4,$2\n\t"
        "b\t4b\n\t"
        "ld\t$16,0($29)\n\t"
        ".set\treorder"
        : : : "memory");
}
