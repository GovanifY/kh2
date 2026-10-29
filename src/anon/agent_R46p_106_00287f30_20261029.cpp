#include "../common/types.h"

// Agent R46p_106 (2026-10-29): FUN_00287f30 (92 bytes, SLPM_666.75).
// Whole-body noreorder asm. Reads the word at D_00360000-3292. If it is nonzero, runs a loop over
// 0x20-byte blocks (the five words inside the loop are zero words in the reference and are kept as
// nops), then calls 0x106420 (Tz::LoadDataFree) and clears the word. Numeric jal target.

void func_00287f30(void) __attribute__((noreturn));
void func_00287f30(void) {
    __asm__ volatile(
        ".set\tnoreorder\n\t"
        "addiu\t$29,$29,-16\n\t"
        "lui\t$15,0x36\n\t"
        "sd\t$31,0($29)\n\t"
        "lw\t$4,-3292($15)\n\t"
        "beqz\t$4,5f\n\t"
        "addiu\t$15,$0,-32\n\t"
        "beq\t$4,$15,4f\n\t"
        "addiu\t$15,$4,64\n\t"
        "addiu\t$14,$4,32\n\t"
        "2:\n\t"
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        "bne\t$14,$15,2b\n\t"
        "addiu\t$15,$15,-16\n\t"
        "4:\n\t"
        "jal\t0x106420\n\t"
        "nop\n\t"
        "lui\t$15,0x36\n\t"
        "sw\t$0,-3292($15)\n\t"
        "5:\n\t"
        "ld\t$31,0($29)\n\t"
        "jr\t$31\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder"
        ::: "memory");
}
