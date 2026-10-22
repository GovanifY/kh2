#include "../common/types.h"

// Agent X03 (2026-10-22): FUN_0016c508, FUN_0016c7a0, FUN_0016d5d0 (SLPM_666.75).
// Each comment says what the code does, then the matching notes.

// Callees.
extern "C" u32 func_0016c028(u32);                 // returns a pointer to a 16-byte record at arg+68 (see agent_u06)
extern "C" u32 func_001ce328(u32);                 // returns a pointer to a sub-record; reads a float at +48
extern "C" void func_002fd188(u32);                // one-time init, called with 0x0016e898
extern "C" void func_0017d538(u32, u32, f32);      // vector helper: (out ptr, word, float in $f12)

// FUN_0016c508 (92 bytes).
// Code: saves a0 in s0 and a1 in s1. Calls func_0016c028(a1), then copies the 16 bytes at
// the returned pointer to a0 (lq/sq through t0). Then calls func_001ce328 with the
// halfword at (word at a1+8) + 78, and stores (a0[1] - float at (result+48)) back to a0[1].
// Returns a0.
// Matching: gcc picks s0/s1 from the use order, which matches the original. The 16-byte
// copy is an asm block (lq/sq through $8) placed after the first call, so the order is the
// original's. Everything else is C.
u32 func_0016c508(u8* a0, u8* a1) {
    u32 v0 = func_0016c028((u32)a1);
    __asm__ volatile(
        "lq\t$8,0(%0)\n\t"
        "sq\t$8,0(%1)\n\t"
        : : "r"(v0), "r"(a0) : "$8", "memory");
    u32 t7 = *(u32*)(a1 + 8);
    v0 = func_001ce328(*(u16*)(t7 + 78));
    *(f32*)(a0 + 4) = *(f32*)(a0 + 4) - *(f32*)(v0 + 48);
    return (u32)a0;
}

// FUN_0016c7a0 (52 bytes).
// Code: calls a virtual slot 0 on the object stored at 0x004f6288 (the global at
// 0x004f0000 + 25224). The arguments are (object, a0, return address), so the caller's ra
// is passed as the third argument. This is not a tail call: the function restores ra and
// returns the callee's result.
// Matching: the lui for the global base is pinned to t7 ($15) with an empty asm barrier, so
// the lw folds 25224 into its offset. The return address is read from $31 after the base
// is loaded, which gives the original order (lui before move a2,ra). The size is not a
// multiple of 8, so this object uses -falign-functions=1.
typedef u32 (*VF3)(u32, u32, u32);
u32 func_0016c7a0(u32 a0) {
    register u32 t asm("$15");
    t = 0x004f0000u;
    __asm__("" : "+r"(t));
    u32 ra;
    __asm__ volatile("move %0, $31" : "=r"(ra));
    u32 obj = *(u32*)(t + 25224);
    VF3 f = *(VF3*)(*(u32*)obj);
    return f(obj, a0, ra);
}

// FUN_0016d5d0 (108 bytes).
// Code: s0 = a0. If the byte at 0x004f6330 is zero, it sets it to 1 and calls
// func_002fd188(0x0016e898) once. Then it calls func_0017d538(&sp0, word at a0+0, float at
// a0+4), where sp0 is a 16-byte local at sp+0. Last, it compares sp with 0x004f6340. If
// they are equal, it stores 0x004f6340 at a0+0. If not, it copies sp0 (16 bytes) to
// 0x004f6340 and then stores 0x004f6340 at a0+0.
// Matching: the whole function is C. The "if (sp != 0x4f6340)" shape with the shared store
// makes gcc emit the original beql (with the sw in the delay slot) and the original
// epilogue order (ld ra, then ld s0). The 16-byte copy is an asm block (lq/sq through $8).
void func_0016d5d0(u8* a0) {
    register u32 t6 asm("$14");
    t6 = 0x004f0000u;
    __asm__("" : "+r"(t6));
    u8* s0 = a0;
    s8 flag = *(s8*)(t6 + 25392);
    if (flag == 0) {
        *(s8*)(t6 + 25392) = 1;
        u32 arg = 0x00170000u;
        __asm__("" : "+r"(arg));
        arg = arg - 5992u;
        func_002fd188(arg);
    }
    u32 sp0[4];
    func_0017d538((u32)sp0, *(u32*)s0, *(f32*)(s0 + 4));
    u32 t7 = 0x004f0000u;
    __asm__("" : "+r"(t7));
    t7 = t7 + 25408u;
    if ((u32)sp0 != t7) {
        __asm__ volatile("lq\t$8,0(%0)\n\tsq\t$8,0(%1)\n\t" : : "r"(sp0), "r"(t7) : "$8", "memory");
    }
    *(u32*)s0 = t7;
}
