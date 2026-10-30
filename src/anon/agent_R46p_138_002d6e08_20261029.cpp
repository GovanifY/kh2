#include "../common/types.h"

extern "C" u8* func_002d5c20(u8* a0, u8* a1);

u8* func_002d6e08(u8* a0, u32 a1, u8* a2) {
    register u8* t asm("$15") = a2 + 32;
    __asm__ volatile("vsub.wxyz $vf1,$vf0,$vf0\n\tsqc2 $vf1,0(%0)" : : "r"(t) : "memory");
    func_002d5c20(a0, a2);
    __asm__ volatile(
        "lwc1 $f0,12(%0)\n\t"
        "lqc2 $vf1,0(%0)\n\t"
        "mfc1 $8,$f0\n\t"
        "qmtc2 $8,$vf2\n\t"
        "vmulx.wxyz $vf1,$vf1,$vf2x\n\t"
        "sqc2 $vf1,0(%0)"
        : : "r"(a0) : "$8", "$f0", "memory");
    *(u32*)(a0 + 8) = 0;
    return a0;
}
