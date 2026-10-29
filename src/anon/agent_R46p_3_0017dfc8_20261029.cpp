#include "../common/types.h"

extern "C" u32 func_0017df70(u32);
extern "C" u32 func_0016e920(u32);
extern "C" u32 func_0016f7d0(u32);

u32 func_0017dfc8(u32 a0) {
    u32 s0 = func_0017df70(a0);
    if (s0 != 0) {
        u32 r = func_0016e920(s0);
        u32 h = *(u16*)(r + 76);
        asm volatile("move $5, %0" : : "r"(r) : "$5");
        if (h == 8) {
            u32 v = func_0016f7d0(s0);
            if (v < 2) {
                s0 = 2077;
            }
        }
    }
    return s0;
}
