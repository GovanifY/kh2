#include "../common/types.h"

// FUN_00186078 (52 bytes). Loop: v = FUN_001b9bc8(a0); a0 = v; return v when v is 0 or
// (v->+1416 & 2) is set, otherwise repeat. The callee has a mangled registry name, so it is
// declared with an asm label. The loop is written so the return value stays in v0.
u32 callee_001b9bc8(u32) asm("_Z16ctarget_001b9bc8jjjj");

u32 r_FUN_00186078(u32 a0) asm("func_00186078");

u32 r_FUN_00186078(u32 a0) {
    u32 v;
    for (;;) {
        v = callee_001b9bc8(a0);
        a0 = v;
        if (v == 0 || (*(u32*)(v + 1416) & 2)) {
            return v;
        }
    }
}
