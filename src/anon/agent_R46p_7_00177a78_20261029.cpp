#include "../common/types.h"

extern "C" void func_00177a38(u8* a0);

// FUN_00177a78 (60 bytes): calls FUN_00177a38(obj), then increments the byte at +2821
// when its value is below 100. The original masks the byte with andi before the compare.
void func_00177a78(u8* a0) {
    func_00177a38(a0);
    u32 c = a0[2821];
    u32 m = c + 1;
    asm volatile("andi %0,%0,0xff" : "+r"(c));
    if (c < 100u) {
        a0[2821] = (u8)m;
    }
}
