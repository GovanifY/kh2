#include "../common/types.h"

// Agent R46p_16 (2026-10-29): func_00191f20 (88 bytes), SLPM_666.75.
// Code: s0 = a0. Calls func_002fd248(a1 & 0xffff7fff, s0 + 8, word at s0 + 4, 8, D_00320000 - 4408).
// If the result is 0, returns 0. Otherwise returns s0 + the word at result + 4.
// Guess: a lookup in a small table keyed by a masked id; the hit gives an offset from the object.

extern "C" u32 func_002fd248(u32, u32, u32, u32, u32);

extern u8 D_00320000[];

u32 func_00191f20(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 r = func_002fd248(a1 & 0xffff7fffu, s0 + 8, *(u32*)(s0 + 4), 8, (u32)&D_00320000[-4408]);
    if (r == 0)
        return 0;
    return s0 + *(u32*)(r + 4);
}
