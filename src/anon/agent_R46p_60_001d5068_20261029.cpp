#include "../common/types.h"

// Agent R46p_60 (2026-10-29): FUN_001d5068 (76 bytes, SLPM_666.75).

extern "C" u32 func_002fd248(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern "C" u32 func_00168b38(u32 a0, u32 a1, u32 a2);
extern "C" u32 func_0023cde8(u32 a0);

// FUN_001d5068: calls FUN_002fd248(arg0, p+8, q, 2, 0x321790) where p is the word at D_01d5ba58
// and q is the word at p+4. Then calls FUN_00168b38(word at 0x35_2758, 47, byte at v0+1) and
// tail-calls FUN_0023cde8(word at r+8).
u32 func_001d5068(u32 a0) {
    u32 base = 0x01d60000;
    asm("" : "+r"(base));
    asm volatile("" ::: "memory");
    u32 k = 0x00320000;
    asm("" : "+r"(k));
    k = k + 6032;
    asm("" : "+r"(k));
    asm volatile("" ::: "memory");
    u32 two = 2;
    asm("" : "+r"(two));
    asm volatile("" ::: "memory");
    u32 p = *(u32*)(base - 17816);
    u32 q = *(u32*)(p + 4);
    u32 v = func_002fd248(a0, p + 8, q, two, k);
    u32 b = *(u8*)(v + 1);
    u32 base2 = 0x00350000;
    asm("" : "+r"(base2));
    u32 r = func_00168b38(*(u32*)(base2 + 10088), 47, b);
    return func_0023cde8(*(u32*)(r + 8));
}
