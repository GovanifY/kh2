#include "../common/types.h"

// Agent W06 (2026-10-22): FUN_0016adc8, FUN_0016ae18, FUN_0016b010 (SLPM_666.75).
// Each comment says what the code does, then how it matches.

// Callees (declared so the registry aliases resolve).
extern "C" void func_0016ace0(u32, u32);  // YS::OBJ::set_pos(const FVector&) (C++ method; this, vector)
extern "C" void func_0016aeb8(u32, f32);  // YS::OBJ::set_rot(float) (C++ method; this, angle)
extern "C" f32 func_002f8ad0(f32, f32);   // f_atan2f(y, x), returns in $f0
extern "C" void func_0016adc8(u32, u32);

typedef u32 V4 __attribute__((vector_size(16)));

// FUN_0016adc8 (76 bytes).
// Code: sets bit 0x200000 in the word at +264, then calls set_pos(a0, a1). Then, if the word at
// +1416 has bit 2 set, zeroes the 16-byte vector at a0+2768 (VU0: vf1 = vf0 - vf0, sqc2).
// Matching: plain C with one VU0 asm block for the zero-and-store pair. The trailing alignment
// nop needs -falign-functions=1 for this object (76 is not a multiple of 8).
void func_0016adc8(u32 a0, u32 a1) {
    *(u32*)(a0 + 264) = *(u32*)(a0 + 264) | 0x200000u;
    func_0016ace0(a0, a1);
    u32 p = a0 + 2768;
    if ((*(u32*)(a0 + 1416) & 2u) != 0) {
        __asm__ volatile(".set noreorder\n\tvsub.wxyz $vf1,$vf0,$vf0\n\tsqc2 $vf1,0(%0)\n\t.set reorder"
                         : : "r"(p) : "memory");
    }
}

// FUN_0016ae18 (64 bytes).
// Code: copies the 16-byte vector at a0+2192 to a stack temp (lq t0 / sq t0), calls
// FUN_0016adc8(a0, &temp), then set_rot(a0, float at +2204).
// Matching: plain C. The source pointer is pinned to $15 (t7) with a "+r" barrier so the addiu
// comes first, the temp is pinned to $8 (t0), and a memory barrier stops the store from landing in
// the jal delay slot, so the frame-address move fills the slot as in the original.
void func_0016ae18(u32 a0) {
    register u8* src asm("$15") = (u8*)a0 + 2192;
    __asm__ volatile("" : "+r"(src));
    register V4 tmp asm("$8");
    tmp = *(V4*)src;
    __asm__ volatile("" : : : "memory");
    u32 pa = (u32)&tmp;
    func_0016adc8(a0, pa);
    func_0016aeb8(a0, *(f32*)(a0 + 2204));
}

// FUN_0016b010 (48 bytes).
// Code: f = atan2f(a1[0], a1[2]) (floats at a1+0 and a1+8 in $f12 and $f13), stores f at a0+1644.
// Matching: the whole body is one noreorder asm block. The original loads $f13 before the prologue
// saves, which GCC will not reproduce from C. The block keeps the original instruction order and
// the move into $16 in the jal delay slot.
void func_0016b010(u32 a0, u32 a1) __attribute__((noreturn));
void func_0016b010(u32 a0, u32 a1) {
    asm volatile(".set\tnoreorder\n\t"
        "addiu\t$29,$29,-16\n\t"
        "lwc1\t$f13,8($5)\n\t"
        "sd\t$16,0($29)\n\t"
        "sd\t$31,8($29)\n\t"
        "lwc1\t$f12,0($5)\n\t"
        "jal\tfunc_002f8ad0\n\t"
        "move\t$16,$4\n\t"
        "swc1\t$f0,1644($16)\n\t"
        "ld\t$31,8($29)\n\t"
        "ld\t$16,0($29)\n\t"
        "jr\t$31\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder\n\t"
        : : : "$4", "$5", "$f0", "$f12", "$f13", "memory");
}
