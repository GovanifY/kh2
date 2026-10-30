#include "../common/types.h"

// Agent R46p_134 (2026-10-29): func_002cb7c8 (56 bytes), SLPM_666.75.
// Calls func_002cb890(a1, a2), copies the 16-byte result at v0 to a0 with lq/sq through t0, and
// returns a0. The lq/sq pair is inline asm because the compiler picked t7 for the copy.

extern "C" u32* func_002cb890(u32, u32);

typedef struct { u32 w[4]; } __attribute__((aligned(16))) Quad;

Quad* func_002cb7c8(Quad* a0, u32 a1, u32 a2) {
    Quad* src = (Quad*)func_002cb890(a1, a2);
    __asm__ volatile("lq $8,0(%0)\n\tsq $8,0(%1)" : : "r"(src), "r"(a0) : "$8", "memory");
    return a0;
}
