#include "../common/types.h"

// Agent R46p_133 (2026-10-29): func_002c5fb8 (64 bytes), SLPM_666.75.
// Calls func_0016bda8(a0), then adds the float at +8 of a0 and the float constant at 0x00375758
// into +8 of a0 and returns a0. Whole-body noreorder asm: the C form put the constant address
// and the ra restore in a different order.

void func_002c5fb8(u32 a0) __attribute__((noreturn));
void func_002c5fb8(u32 a0) {
    __asm__ volatile(
        ".set\tnoreorder\n\t"
        "addiu\t$29,$29,-16\n\t"
        "sd\t$16,0($29)\n\t"
        "sd\t$31,8($29)\n\t"
        "jal\t0x16bda8\n\t"
        "move\t$16,$4\n\t"
        "lui\t$15,0x37\n\t"
        "lwc1\t$f0,8($16)\n\t"
        "addiu\t$15,$15,22360\n\t"
        "ld\t$31,8($29)\n\t"
        "lwc1\t$f1,0($15)\n\t"
        "move\t$2,$16\n\t"
        "add.s\t$f0,$f0,$f1\n\t"
        "swc1\t$f0,8($16)\n\t"
        "ld\t$16,0($29)\n\t"
        "jr\t$31\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder"
        : : : "memory");
}
