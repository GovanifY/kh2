#include "../common/types.h"

extern u8 D_01da0000[];
extern "C" void func_001e7798(u32, u32) asm("func_001e7798");

void func_001ea928(u32 a0, u32 a1) {
    u32 p = *(u32*)(a1 + 12);
    a0 = a0 + *(u32*)p;
    u32 s = a0 + 160;
    u32 v = *(u32*)(s + 12);
    if (v != 0) {
        func_001e7798(*(u32*)&D_01da0000[-6428], v);
        *(u32*)(s + 12) = 0;
    }
}
