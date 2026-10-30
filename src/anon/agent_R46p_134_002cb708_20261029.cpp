#include "../common/types.h"

// Agent R46p_134 (2026-10-29): func_002cb708 (56 bytes), SLPM_666.75.
// Calls AREA::Free(*(a0 + 128)) (jal 0x105110, lw in the delay slot), then calls 0x325320 with
// (0x01E2BE18, a0) and returns. Whole-body noreorder asm: the C form tail-called the second call
// and folded the constant into lui/ori, neither of which matches the original.

void func_002cb708(u32 a0) __attribute__((noreturn));
void func_002cb708(u32 a0) {
    __asm__ volatile(
        ".set\tnoreorder\n\t"
        "addiu\t$29,$29,-16\n\t"
        "sd\t$16,0($29)\n\t"
        "sd\t$31,8($29)\n\t"
        "move\t$16,$4\n\t"
        "jal\t0x105110\n\t"
        "lw\t$4,128($4)\n\t"
        "lui\t$4,0x1e3\n\t"
        "move\t$5,$16\n\t"
        "jal\t0x325320\n\t"
        "addiu\t$4,$4,-16872\n\t"
        "ld\t$16,0($29)\n\t"
        "ld\t$31,8($29)\n\t"
        "jr\t$31\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder"
        : : : "memory");
}
