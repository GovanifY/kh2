#include "../common/types.h"

// FUN_002c1950 (64 bytes), SLPM_666.75. Calls func_0017f488(arg1+320, 0, c, 0.0f), where c is the float at
// 0x3754e8 (8.0f), then tail-calls func_002c5fa0(arg1).
// Whole-body noreorder asm: plain C did not reproduce the lui/addiu split, the sd ra position, or the
// argument-register order (see the notes).
void func_002c1950(u8* a0, u8* a1) __attribute__((noreturn));
void func_002c1950(u8* a0, u8* a1) {
    __asm__ volatile(
        ".set\tnoreorder\n\t"
        "addiu\t$29,$29,-16\n\t"
        "mtc1\t$0,$f13\n\t"
        "sd\t$16,0($29)\n\t"
        "lui\t$15,0x37\n\t"
        "addiu\t$15,$15,21736\n\t"
        "sd\t$31,8($29)\n\t"
        "daddu\t$16,$5,$0\n\t"
        "lwc1\t$f12,0($15)\n\t"
        "addiu\t$4,$5,320\n\t"
        "jal\t0x17f488\n\t"
        "daddu\t$5,$0,$0\n\t"
        "daddu\t$4,$16,$0\n\t"
        "ld\t$31,8($29)\n\t"
        "ld\t$16,0($29)\n\t"
        "j\t0x2c5fa0\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder\n\t");
}
