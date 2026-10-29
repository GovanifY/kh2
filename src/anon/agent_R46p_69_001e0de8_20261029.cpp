#include "../common/types.h"

// FUN_001e0de8 (84 bytes, 21 instructions, non-leaf). Saves s0 and ra, calls FUN_001e0cc8(a0) and
// keeps a0 in s0. Copies 16 bytes from the returned pointer to s0 (lq/sq through $8) unless it is
// already s0, stores zero at s0+12, then a noreorder asm block makes the call FUN_001e0ce8(s0) with
// the move a0,s0 before the jal and addiu s0,16 in its delay slot; the result stays in $2. Copies
// the result to s0 unless it equals the new s0. Needs -falign-functions=1 (84 bytes).
extern "C" u8* func_001e0cc8(u8* a0);

void r_func_001e0de8(u8* a0) asm("func_001e0de8");

void r_func_001e0de8(u8* a0) {
    register u8* s0 asm("$16") = a0;
    u8* v = func_001e0cc8(a0);
    if (s0 != v) {
        asm volatile("lq $8,0(%0)\n\tsq $8,0(%1)" : : "r"(v), "r"(s0) : "$8", "memory");
    }
    *(u32*)(s0 + 12) = 0;
    register u8* w asm("$2");
    asm volatile(
        ".set noreorder\n\t"
        "daddu $4,$16,$0\n\t"
        "jal 0x1e0ce8\n\t"
        "addiu %1,%1,16\n\t"
        ".set reorder"
        : "=r"(w), "+r"(s0)
        :
        : "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$24", "$25", "$31", "memory");
    if (s0 != w) {
        asm volatile("lq $8,0(%0)\n\tsq $8,0(%1)" : : "r"(w), "r"(s0) : "$8", "memory");
    }
}
