#include "../common/types.h"

// Agent R46j_2 (2026-10-23): FUN_00171418 (72 bytes), SLPM_666.75.
// Saves s0 and ra in a 16-byte frame, s0 = a0, t7 = word at 0(a0), calls func_0016c028(word at 4(t7)).
// If the result is not the slot 0x01c5f480, copies 16 bytes from the result into the slot (copy via $8).
// Always stores the slot address at 0(s0). The slot is built in $15 with lui/addiu (hi 0x1c6, lo -2944).
extern "C" void* func_0016c028(u32 a0);
extern "C" void func_00171418(u32* s0);

void func_00171418(u32* s0) {
    u32* p1 = (u32*)s0[0];
    void* v = func_0016c028(p1[1]);
    register u32* slot asm("$15");
    asm("lui $15,0x1c6\n\taddiu $15,$15,-2944" : "=r"(slot));
    if (v != (void*)slot) {
        asm volatile(
            "lq $8,0(%0)\n\t"
            "sq $8,0(%1)"
            :
            : "r"(v), "r"(slot)
            : "$8", "memory");
    }
    s0[0] = (u32)slot;
}
