#include "../common/types.h"

// Agent R46p_57 (2026-10-29): FUN_001cd4c0 (96 bytes), SLPM_666.75.
// Frame of 16 bytes, saves ra. Calls func_001bbf00(); a nonzero result returns 1. Otherwise reads the
// halfword at 0x330000 - 17696 + 4 and tests it < 51; if so, reads the byte at 0x350000 + 888 and, when
// zero, calls func_001bb4a0(); the result is 1 when that returns zero. Otherwise returns 0.
// Whole-body noreorder asm in a noreturn C function (form a): the delay-slot li/move values and the
// branch senses are kept literally.
void func_001cd4c0(void) __attribute__((noreturn));
void func_001cd4c0(void) {
    __asm__ volatile(
        ".set\tnoreorder\n\t"
        "addiu\t$29,$29,-16\n\t"
        "sd\t$31,0($29)\n\t"
        "jal\t0x1bbf00\n\t"
        "nop\n\t"
        "bnez\t$2,1f\n\t"
        "addiu\t$15,$0,1\n\t"
        "lui\t$15,0x33\n\t"
        "addiu\t$15,$15,-17696\n\t"
        "lhu\t$14,4($15)\n\t"
        "sltiu\t$14,$14,51\n\t"
        "beqz\t$14,2f\n\t"
        "lui\t$15,0x35\n\t"
        "lbu\t$14,888($15)\n\t"
        "bnez\t$14,1f\n\t"
        "daddu\t$15,$0,$0\n\t"
        "jal\t0x1bb4a0\n\t"
        "nop\n\t"
        "beqz\t$2,1f\n\t"
        "addiu\t$15,$0,1\n\t"
        "2:\n\t"
        "daddu\t$15,$0,$0\n\t"
        "1:\n\t"
        "ld\t$31,0($29)\n\t"
        "daddu\t$2,$15,$0\n\t"
        "jr\t$31\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder\n\t");
}
