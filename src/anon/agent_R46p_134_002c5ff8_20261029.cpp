#include "../common/types.h"

// Agent R46p_134 (2026-10-29): func_002c5ff8 (84 bytes), SLPM_666.75.
// Zeroes the 16-byte vector at a0+32 (VU0 vsub.wxyz vf1 then sqc2). Calls func_00143e50 (Octree::getNormal
// entry, u16 a1 masked with andi, flag 0) with a stack buffer, then calls func_00186a90(a0, buffer, float)
// with the float constant at 0x0037575c in f12. Whole-body noreorder asm, since the VU0 store and the
// float in f12 are not expressible in C here. Needs -falign-functions=1 (size 84).

void func_002c5ff8(u32 a0, u32 a1) __attribute__((noreturn));
void func_002c5ff8(u32 a0, u32 a1) {
    __asm__ volatile(
        ".set\tnoreorder\n\t"
        "addiu\t$29,$29,-32\n\t"
        "addiu\t$15,$4,32\n\t"
        "sd\t$16,16($29)\n\t"
        "sd\t$31,24($29)\n\t"
        "move\t$16,$4\n\t"
        "vsub.wxyz\t$vf1,$vf0,$vf0\n\t"
        "sqc2\t$vf1,0($15)\n\t"
        "move\t$4,$29\n\t"
        "move\t$6,$0\n\t"
        "jal\t0x143e50\n\t"
        "andi\t$5,$5,0xffff\n\t"
        "lui\t$15,0x37\n\t"
        "move\t$4,$16\n\t"
        "addiu\t$15,$15,22364\n\t"
        "move\t$5,$29\n\t"
        "jal\t0x186a90\n\t"
        "lwc1\t$f12,0($15)\n\t"
        "ld\t$16,16($29)\n\t"
        "ld\t$31,24($29)\n\t"
        "jr\t$31\n\t"
        "addiu\t$29,$29,32\n\t"
        ".set\treorder"
        : : : "memory");
}
