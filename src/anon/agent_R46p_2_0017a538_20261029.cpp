#include "../common/types.h"

// FUN_0017a538 (84 bytes): calls FUN_0016a070(obj). If the result is 1, returns 1 when obj->+2896 is
// non-zero and below 7, else 0. Any other result returns 0.
extern "C" s32 func_0016a070(void *p);

s32 func_0017a538(void *a0) {
    register void *p asm("$16");
    register s32 acc asm("$17");
    register s32 x asm("$15");
    s32 c;
    p = a0;
    acc = 0;
    if (func_0016a070(p) == 1) {
        x = *(s32 *)((u8 *)p + 2896);
        asm("xori %0,%1,0" : "=r"(c) : "r"(x));
        x = x < 7;
        if (c == 0) x = 0;
        acc = x;
    }
    return acc;
}
