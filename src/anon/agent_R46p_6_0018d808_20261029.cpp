#include "../common/types.h"

// Agent R46p_6 (2026-10-29): FUN_0018d808 (52 bytes), SLPM_666.75.
// Calls func_0016c028(word at a1+8), copies the 16 bytes at the returned pointer to a0 (lq/sq
// through $8), and returns a0.
// Matching: C prologue and call, with the 16-byte copy as one asm block after the call.
// The size is not a multiple of 8, so this object uses -falign-functions=1.
extern "C" void* func_0016c028(u32 a0);

u32 func_0018d808(u32* a0, u32* a1) {
    void* v = func_0016c028(a1[2]);
    asm volatile(
        "lq $8,0(%0)\n\t"
        "sq $8,0(%1)"
        :
        : "r"(v), "r"(a0)
        : "$8", "memory");
    return (u32)a0;
}
