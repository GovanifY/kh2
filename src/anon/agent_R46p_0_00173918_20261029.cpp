#include "../common/types.h"

// Agent R46p_0 (2026-10-29): FUN_00173918 (104 bytes, SLPM_666.75).

typedef int u128 __attribute__((mode(TI)));

extern "C" void func_002fd188(u32 a0);

extern s8 D_01c5f4f0[];
extern u8 D_00170000[];
extern u8 D_01c5f500[];

// FUN_00173918: if the flag byte D_01c5f4f0 is clear, set it and call func_002fd188 with the string at
// D_00170000+21824. Then take the pointer stored at *arg0, read the word at +4 of that object, add 2144
// to it to form src, and if src differs from D_01c5f500, copy 16 bytes from src to D_01c5f500. Store
// D_01c5f500 back at *arg0.
void func_00173918(u32 p) {
    register u32 pp asm("$16");
    register u32 obj asm("$15");
    register u32 src asm("$13");
    register u32 dst asm("$14");
    register u128 tmp asm("$8");
    pp = p;
    if (D_01c5f4f0[0] == 0) {
        D_01c5f4f0[0] = 1;
        func_002fd188((u32)D_00170000 + 21824);
    }
    obj = *(u32*)pp;
    src = *(u32*)(obj + 4);
    src = src + 2144;
    dst = (u32)D_01c5f500;
    if (src != dst) {
        tmp = *(u128*)src;
        asm volatile("" : "+r"(dst));
        *(u128*)dst = tmp;
    }
    *(u32*)pp = dst;
}
