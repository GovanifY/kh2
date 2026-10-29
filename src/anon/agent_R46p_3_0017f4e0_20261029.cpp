#include "../common/types.h"

extern "C" u32 func_0017ec98(u32);
extern "C" u32 func_0017edf0(u32);
extern "C" u32 func_00168b38(u32, u32, u32);

u32 func_0017f4e0(u32 a0) {
    u32 q = func_0017ec98(a0);
    asm volatile("move $5, %0" : : "r"(q) : "$5");
    u32 r = func_0017edf0(a0);
    u32 t;
    if (r == 0) {
        goto zero;
    }
    {
        u32 v = func_00168b38(r, 9, 0);
        if (*(u32*)(a0 + 12) != *(u32*)(v + 8)) {
            t = 1;
            goto done;
        }
    }
zero:
    t = 0;
done:
    return t;
}
