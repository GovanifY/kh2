#include "../common/types.h"

// Agent R46p_106 (2026-10-29): FUN_00287760 (64 bytes, SLPM_666.75).
// Saves s0 and ra, s0 = a0, calls 0x2878c8(a0), then calls the vtable slot +20 of the object at
// *(a0+0) with a0 = that object and s0 += 12 in the jalr delay slot, then calls 0x23f848(s0).
// Whole-body noreorder asm: the epilogue restores interleave with the tail-position call shape.
// Numeric jal targets keep the callees out of the registry.

void func_00287760(void) __attribute__((noreturn));
void func_00287760(void) {
    __asm__ volatile(
        ".set\tnoreorder\n\t"
        "addiu\t$29,$29,-16\n\t"
        "sd\t$16,0($29)\n\t"
        "sd\t$31,8($29)\n\t"
        "jal\t0x2878c8\n\t"
        "daddu\t$16,$4,$0\n\t"
        "lw\t$4,0($16)\n\t"
        "lw\t$14,0($4)\n\t"
        "lw\t$15,20($14)\n\t"
        "jalr\t$15\n\t"
        "addiu\t$16,$16,12\n\t"
        "jal\t0x23f848\n\t"
        "daddu\t$4,$16,$0\n\t"
        "ld\t$16,0($29)\n\t"
        "ld\t$31,8($29)\n\t"
        "jr\t$31\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder"
        ::: "memory");
}
