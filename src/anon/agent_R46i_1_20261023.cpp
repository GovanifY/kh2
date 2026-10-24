#include "../common/types.h"

typedef int u128 __attribute__((mode(TI)));

// FUN_0016dad8 (72 bytes): calls FUN_0017d050(&tmp, *a0) with a 16-byte local tmp. Then if &tmp != 0x004f62a0,
// copies tmp (16 bytes) to 0x004f62a0 (lq/sq). Stores 0x004f62a0 at *a0 with a branch-likely sw in the delay slot.
// Whole-body noreorder asm; gcc owns the 32-byte frame via the u128 local.
extern "C" void func_0017d050(u32 a0, u32 a1);
void func_0016dad8(u32* a0) {
    u128 tmp[2];
    __asm__ volatile(
        ".set\tnoreorder\n\t"
        "sd\t$16,16($29)\n\t"
        "sd\t$31,24($29)\n\t"
        "move\t$16,$4\n\t"
        "lw\t$5,0($4)\n\t"
        "jal\t0x17d050\n\t"
        "move\t$4,$29\n\t"
        "lui\t$15,0x4f\n\t"
        "addiu\t$15,$15,25248\n\t"
        "beql\t$29,$15,1f\n\t"
        "sw\t$15,0($16)\n\t"
        "lq\t$8,0($29)\n\t"
        "sq\t$8,0($15)\n\t"
        "sw\t$15,0($16)\n\t"
        "1:\n\t"
        "ld\t$31,24($29)\n\t"
        "ld\t$16,16($29)\n\t"
        ".set\treorder"
        : "=m"(tmp) : : "$4","$5","$8","$15","memory");
}

// FUN_0016e000 (72 bytes): f = *a0 * *(f32*)0x36c258; v = (s32)f (cvt.w.s); r = FUN_0014aba8(a0, a1);
// return FUN_0014aa58(r, v, 0). Whole-body noreorder asm; the final j has its addiu in the delay slot.
extern "C" u32 func_0014aba8(f32* a0, u32 a1);
extern "C" u32 func_0014aa58(u32 a0, u32 a1, u32 a2);
u32 func_0016e000(f32* a0, u32 a1) {
    u128 frame;
    __asm__ volatile(
        ".set\tnoreorder\n\t"
        "lui\t$15,0x37\n\t"
        "sd\t$16,0($29)\n\t"
        "addiu\t$15,$15,-15784\n\t"
        "sd\t$31,8($29)\n\t"
        "lwc1\t$f1,0($15)\n\t"
        "lwc1\t$f0,0($4)\n\t"
        "mul.s\t$f0,$f0,$f1\n\t"
        "cvt.w.s\t$f1,$f0\n\t"
        "jal\t0x14aba8\n\t"
        "mfc1\t$16,$f1\n\t"
        "move\t$5,$16\n\t"
        "ld\t$31,8($29)\n\t"
        "ld\t$16,0($29)\n\t"
        "move\t$4,$2\n\t"
        "move\t$6,$0\n\t"
        "j\t0x14aa58\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder"
        : "=m"(frame) : : "$2","$4","$5","$6","$15","$f0","$f1","memory");
}

// FUN_0016e500 (60 bytes): v = FUN_001dc670(*a0); if (v != a0[1]) copy 16 bytes from a0[1] to v (lq/sq).
// Whole-body noreorder asm; gcc owns the 16-byte frame via the u128 local.
extern "C" u32 func_001dc670(u32 a0);
void func_0016e500(u32* a0) {
    u128 frame;
    __asm__ volatile(
        ".set\tnoreorder\n\t"
        "sd\t$16,0($29)\n\t"
        "sd\t$31,8($29)\n\t"
        "move\t$16,$4\n\t"
        "jal\t0x1dc670\n\t"
        "lw\t$4,0($4)\n\t"
        "lw\t$15,4($16)\n\t"
        "beq\t$2,$15,1f\n\t"
        "ld\t$16,0($29)\n\t"
        "lq\t$8,0($15)\n\t"
        "sq\t$8,0($2)\n\t"
        "ld\t$16,0($29)\n\t"
        "1:\n\t"
        "ld\t$31,8($29)\n\t"
        "jr\t$31\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder"
        : "=m"(frame) : : "$2","$4","$8","$15","memory");
}
