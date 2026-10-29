#include "../common/types.h"

// FUN_0017a6c8 (76 bytes): calls FUN_0019ba60(*(D_00350000 - 5816)). If the result is non-zero, returns
// whether the word at +352 of *(D_00350000 - 5816) has bit 0x4000 set. Otherwise returns 0.
extern u8 D_00350000[];
extern "C" s32 func_0019ba60(u32 p);

s32 func_0017a6c8(void) {
    s32 r = 0;
    if (func_0019ba60(*(u32 *)&D_00350000[-5816])) {
        u8 *p = *(u8 **)&D_00350000[-5816];
        u32 t = *(u32 *)(p + 352) & 0x4000u;
        asm volatile("" : "+r"(t));
        r = t != 0;
    }
    return r;
}
