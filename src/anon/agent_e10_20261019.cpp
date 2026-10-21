#include "../common/types.h"

typedef int u128 __attribute__((mode(TI)));
extern u8 D_00370000[];
extern u8 D_0036DEFC[];
extern u8 D_0036DF00[];
extern u8 D_001c6320[];

// FUN_00243190 (48 bytes): linear search of 11 u32 words at 0x3718D0 for a0. Returns the
// index of the first match, or 11 if none.
u32 func_00243190(u32 a0) {
    register u32 v0 asm("$2");
    register u32 w asm("$15");
    u32* p = (u32*)&D_00370000[6352];
    asm("" : "+r"(p));
    v0 = 0;
    do {
        w = *p;
        if (w == a0) break;
        p++;
        v0++;
    } while (v0 < 11);
    return v0;
}

// FUN_001c6400 (92 bytes): scales the 4-vector at a1 by the float at 0x0036DEFC (VU0
// vmulx.wxyz) into a 16-byte stack temp, copies it into a0+64 unless that is the temp
// itself, then sets a0+84 = &D_001c6320 and a0+76 = float at 0x0036DF00.
// Only the VU0 sequence is asm; the rest is C. Empty "+r" barriers keep the lui/addiu
// pairs and make the lui land in the beql delay slot.
void func_001c6400(u8* a0, u8* a1) {
    u128 tmp;
    register u128* d asm("$15");
    register u8* p asm("$15") = D_0036DEFC;
    register u128 v asm("$8");
    asm volatile("" : "+r"(p));
    f32 c = *(f32*)p;
    d = (u128*)(a0 + 64);
    asm volatile("" : "+r"(d));
    asm volatile("lqc2 $vf1,0(%1)\n\tmfc1 $8,%2\n\tqmtc2 $8,$vf2\n\tvmulx.wxyz $vf1,$vf1,$vf2x\n\tsqc2 $vf1,%0"
                 : "=m"(tmp) : "r"(a1), "f"(c) : "$8");
    if (d != &tmp) { asm volatile("" : "+r"(d)); v = tmp; *d = v; }
    p = D_001c6320;
    asm volatile("" : "+r"(p));
    *(u8**)(a0 + 84) = p;
    p = D_0036DF00;
    asm volatile("" : "+r"(p));
    *(f32*)(a0 + 76) = *(f32*)p;
}
