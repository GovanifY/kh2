#include "../common/types.h"

// Agent R46p_140 (2026-10-29): FUN_002d96d8 (84 bytes, SLPM_666.75).

void func_002d0ea8(u32);

// FUN_002d96d8: calls func_002d0ea8(this) for the base step, then stores the vtable at this+0
// (0x3625e0), sets two flag bytes and zeroes a few words in the object. Memory barriers keep the
// instruction order of the original.
void func_002d96d8(u8* a0) {
    func_002d0ea8((u32)a0);
    u32 vt = 0x360000u;
    asm volatile("" : "+r"(vt));
    *(u32*)(a0 + 3224) = 0;
    asm volatile("" ::: "memory");
    u8 one = 1;
    asm volatile("" : "+r"(one));
    *(u32*)(a0 + 3056) = 0;
    asm volatile("" ::: "memory");
    vt = vt + 9696u;
    asm volatile("" : "+r"(vt));
    *(u8*)(a0 + 3076) = one;
    asm volatile("" ::: "memory");
    *(u32*)a0 = vt;
    asm volatile("" ::: "memory");
    *(u32*)(a0 + 3060) = 0;
    asm volatile("" ::: "memory");
    *(u8*)(a0 + 3068) = one;
    asm volatile("" ::: "memory");
    *(u32*)(a0 + 3072) = 0;
    asm volatile("" ::: "memory");
    *(u32*)(a0 + 3216) = 0;
    asm volatile("" ::: "memory");
    *(u32*)(a0 + 3220) = 0;
}
