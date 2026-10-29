#include "../common/types.h"

// Agent R46p_57 (2026-10-29): FUN_001c1d90 (100 bytes), SLPM_666.75.
// Frame of 16 bytes. a0 = a1 and s0 = a1; sd s0 is saved before sd ra. If the word at s0+2732 is zero,
// calls func_0016bd60(s0, 5), then tail-jumps to func_0017f488(s0+320, 0) with a float constant in
// $f12. Otherwise tail-jumps to 0x001c1fe0 with a0 = s0.
// Whole-body noreorder asm in a noreturn C function (form a): plain C does not reproduce the prologue
// order (the move before sd s0 / sd ra) or the delay-slot restores.
void func_001c1d90(u8* a0, u8* a1) __attribute__((noreturn));
void func_001c1d90(u8* a0, u8* a1) {
    __asm__ volatile(
        ".set\tnoreorder\n\t"
        "addiu\t$29,$29,-16\n\t"
        "daddu\t$4,$5,$0\n\t"
        "sd\t$16,0($29)\n\t"
        "sd\t$31,8($29)\n\t"
        "daddu\t$16,$5,$0\n\t"
        "lw\t$15,2732($16)\n\t"
        "bnez\t$15,1f\n\t"
        "addiu\t$5,$0,5\n\t"
        "jal\t0x16bd60\n\t"
        "nop\n\t"
        "lui\t$15,0x37\n\t"
        "mtc1\t$0,$f13\n\t"
        "addiu\t$4,$16,320\n\t"
        "ld\t$31,8($29)\n\t"
        "addiu\t$15,$15,-8848\n\t"
        "ld\t$16,0($29)\n\t"
        "lwc1\t$f12,0($15)\n\t"
        "daddu\t$5,$0,$0\n\t"
        "j\t0x17f488\n\t"
        "addiu\t$29,$29,16\n\t"
        "1:\n\t"
        "daddu\t$4,$16,$0\n\t"
        "ld\t$31,8($29)\n\t"
        "ld\t$16,0($29)\n\t"
        "j\t0x1c1fe0\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder\n\t");
}
