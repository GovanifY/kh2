#include "../common/types.h"

// Agent R46p_106 (2026-10-29): FUN_00287ed8 (84 bytes, SLPM_666.75).
// Whole-body noreorder asm. a1 = a0; if the word at D_00360000-3292 is nonzero, skip. Otherwise
// allocate 80 bytes via 0x1063c0 (a0 = 80), store the result in s0 and the word, then call 0x167658(v0, 0).
// Tail-jumps to 0x288018 with the frame popped in its delay slot.
// Numeric jal/j targets keep the callees out of the registry; lui 0x36 base is in $17.

void func_00287ed8(void) __attribute__((noreturn));
void func_00287ed8(void) {
    __asm__ volatile(
        ".set\tnoreorder\n\t"
        "addiu\t$29,$29,-32\n\t"
        "daddu\t$5,$4,$0\n\t"
        "sd\t$17,8($29)\n\t"
        "sd\t$16,0($29)\n\t"
        "sd\t$31,16($29)\n\t"
        "lui\t$17,0x36\n\t"
        "lw\t$15,-3292($17)\n\t"
        "bnez\t$15,1f\n\t"
        "addiu\t$4,$0,80\n\t"
        "jal\t0x1063c0\n\t"
        "nop\n\t"
        "daddu\t$16,$2,$0\n\t"
        "daddu\t$4,$2,$0\n\t"
        "jal\t0x167658\n\t"
        "daddu\t$5,$0,$0\n\t"
        "sw\t$16,-3292($17)\n\t"
        "1:\n\t"
        "ld\t$16,0($29)\n\t"
        "ld\t$17,8($29)\n\t"
        "ld\t$31,16($29)\n\t"
        "j\t0x288018\n\t"
        "addiu\t$29,$29,32\n\t"
        ".set\treorder"
        ::: "memory");
}
