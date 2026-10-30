#include "../common/types.h"

// FUN_002c1aa0 (68 bytes): base ctor call, then set vtable 0x361b20, flag bit 0 at +1420,
// clear word +2788 and byte +2792.
extern "C" void func_002be770(u32);
extern u8 D_00360000;

void func_002c1aa0(u8* a0) {
    func_002be770((u32)a0);
    u32 f = *(u32*)(a0 + 1420);
    __asm__ __volatile__("" ::: "memory");
    u32 vt = (u32)&D_00360000 + 6944u;
    __asm__ __volatile__("" : "+r"(vt));
    __asm__ __volatile__("" ::: "memory");
    *(u32*)(a0 + 2788) = 0;
    __asm__ __volatile__("" ::: "memory");
    u32 nf = f | 1;
    __asm__ __volatile__("" : "+r"(nf));
    *(u32*)a0 = vt;
    __asm__ __volatile__("" ::: "memory");
    *(u32*)(a0 + 1420) = nf;
    __asm__ __volatile__("" ::: "memory");
    *(u8*)(a0 + 2792) = 0;
}
