#include "../common/types.h"

// ---------------------------------------------------------------------------
// FUN_0015cc18 (52 bytes), matched.
// Code: writes four bytes (a, b, c, d) to the 4-byte record at
//       D_004f3704 + i*4 (byte 0 = a, 1 = b, 2 = c, 3 = d).
// Guess: stores a 4-byte colour/entry into a fixed table indexed by i.
// Note: the args are u8 so the compiler emits the andi on each argument.
// ---------------------------------------------------------------------------
extern u8 D_004f3704[];

void func_0015cc18(s32 i, u8 a, u8 b, u8 c, u8 d) {
    u8* p = D_004f3704 + i * 4;
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = d;
}

// ---------------------------------------------------------------------------
// FUN_00165ef0 (52 bytes), matched.
// Code: start from a0 (or the global at D_004f41c0 when a0 is NULL). Each pass
//       takes word +12 of the current node (or the global when the node is
//       NULL). Stops at a NULL result, or at a node whose flag word at +8 has
//       bit 1 clear. Returns the last node visited.
// Guess: walks a parent/next chain of nodes that carry a "continue" flag.
// Note: the global is read once, before the loop. The pointer is
//       reassigned on every pass, including the one that ends the loop.
// ---------------------------------------------------------------------------
extern u32 D_004f41c0;

u32* func_00165ef0(u32* a0) {
    u32* g = (u32*)D_004f41c0;
    u32* v;
    for (;;) {
        v = a0 ? (u32*)a0[3] : g;
        a0 = v;
        if (!v || !(v[2] & 2))
            return v;
    }
}
