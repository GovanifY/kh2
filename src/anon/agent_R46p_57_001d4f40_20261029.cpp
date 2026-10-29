#include "../common/types.h"

// Agent R46p_57 (2026-10-29): FUN_001d4f40 (104 bytes), SLPM_666.75.
// Float body. Frame of 32 bytes, saves f20 at 16(sp), s0 and ra. Converts a2 and a1 to float with cvt.s.w.
// Calls func_002f8b30 with the float at 0x370000 - 6864 in $f12, then f20 *= result. t = trunc(f20), or 1
// if that is zero (movz). Tail-jumps to func_001d1b60(s0, a1 + t) after reading the int at s0+44 as a1.
// Whole-body noreorder asm in a noreturn C function (form a): the float saves and the movz are kept literally.
void func_001d4f40(u8* a0, s32 a1, s32 a2) __attribute__((noreturn));
void func_001d4f40(u8* a0, s32 a1, s32 a2) {
    __asm__ volatile(
        ".set\tnoreorder\n\t"
        "addiu\t$29,$29,-32\n\t"
        "mtc1\t$6,$f13\n\t"
        "swc1\t$f20,16($29)\n\t"
        "lui\t$15,0x37\n\t"
        "sd\t$16,0($29)\n\t"
        "cvt.s.w\t$f13,$f13\n\t"
        "mtc1\t$5,$f20\n\t"
        "addiu\t$15,$15,-6864\n\t"
        "sd\t$31,8($29)\n\t"
        "daddu\t$16,$4,$0\n\t"
        "cvt.s.w\t$f20,$f20\n\t"
        "jal\t0x2f8b30\n\t"
        "lwc1\t$f12,0($15)\n\t"
        "mul.s\t$f20,$f20,$f0\n\t"
        "lw\t$5,44($16)\n\t"
        "daddu\t$4,$16,$0\n\t"
        "ld\t$31,8($29)\n\t"
        "addiu\t$15,$0,1\n\t"
        "ld\t$16,0($29)\n\t"
        "cvt.w.s\t$f0,$f20\n\t"
        "mfc1\t$14,$f0\n\t"
        "lwc1\t$f20,16($29)\n\t"
        "movz\t$14,$15,$14\n\t"
        "addu\t$5,$5,$14\n\t"
        "j\t0x1d1b60\n\t"
        "addiu\t$29,$29,32\n\t"
        ".set\treorder\n\t");
}
