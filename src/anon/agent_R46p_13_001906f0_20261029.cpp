#include "../common/types.h"

// Agent R46p_13 (2026-10-29): FUN_001906f0 (64 bytes, SLPM_666.75).
// Code: zeroes the word at sp+12 and calls func_001902a8(a0, sp), with the first argument
// passed through. Then copies the 16 bytes at a1 (kept in s0) to sp+32 (lq/sq through $8)
// and calls func_0018a970(sp, sp+32).
// Matching: C with asm for the copy. The copy block computes sp+32 itself (addiu in the
// asm), so the temp address is not kept in a saved register across the first call.
// The frame is 48 bytes of locals (buf[12]) plus s0 and ra.

extern "C" void func_001902a8(u32 a0, u32 a1);
extern "C" void func_0018a970(u32 a0, u32 a1);

void func_001906f0(u32 a0, u32 a1) {
    u32 buf[12];
    register u32 src asm("$16");
    src = a1;
    __asm__ volatile("" : "+r"(src));
    buf[3] = 0;
    func_001902a8(a0, (u32)buf);
    u32 tmp;
    __asm__ volatile(
        "addiu\t%1,$29,32\n\t"
        "lq\t$8,0(%0)\n\t"
        "sq\t$8,0(%1)\n\t"
        : "+r"(src), "=r"(tmp) : : "$8", "memory");
    func_0018a970((u32)buf, tmp);
}
