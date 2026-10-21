#include "../common/types.h"

// 16-byte block used by the struct copies in FUN_0013fd10. Aligned so the compiler
// uses lq/sq for it, as the original does.
struct __attribute__((aligned(16))) S26V4 {
    u32 x;
    u32 y;
    u32 z;
    u32 w;
};

// Callees. Each one is either a registered function in another object or an unregistered
// asm function. They are declared extern "C" so they resolve through the plain symbols.
extern "C" void func_0016af58(S26V4* a0, u32 a1);
extern "C" f32 func_0013fcd8(u8* a0, S26V4* a1);
extern "C" void func_0013fd78(u8* a0);
extern "C" void func_0013f5f0(u8* a0);
extern "C" u32 func_00167f18(u32 a0);
extern "C" u32 func_00140618(u8* a0, u32 a1);

// FUN_0013fd10 (100 bytes)
// Code: frame of 64 bytes (s0, s1, s2, ra). tmp = the 16-byte block at sp+16 (s0), and
// func_0016af58(tmp, a0->+68) fills it. Then a self-copy guard: if the block at sp
// is not the same as tmp, copy tmp to sp and back to tmp. Returns func_0013fcd8(a0, tmp).
// Matching: the 16-byte copy is one noreorder asm block (lq/sq through $8, base sp
// used directly, guard beq). Plain C struct copies got the temp and the sp base wrong.
// The unused "=r" output on $18 makes gcc save s2 with sd and keep the frame at 64.
// Needs -falign-functions=1 (100 bytes).
f32 func_0013fd10(u8* a0) {
    S26V4 tmp2;
    S26V4 tmp;
    register u32 unused_s2 asm("$18");
    func_0016af58(&tmp, *(u32*)(a0 + 68));
    asm volatile("" : "=r"(unused_s2));
    asm volatile(
        ".set noreorder\n\t"
        "beq $29, %0, 1f\n\t"
        " nop\n\t"
        "lq $8, 0(%0)\n\t"
        "sq $8, 0($29)\n"
        "1:\n\t"
        "lq $8, 0($29)\n\t"
        "sq $8, 0(%0)\n\t"
        ".set reorder"
        : : "r"(&tmp) : "$8", "memory");
    return func_0013fcd8(a0, &tmp);
}

// FUN_0013fec0 (72 bytes)
// Code: f = FUN_0013fd10(a0). Stores f at a0+80. Calls FUN_0013fd78(a0). Then copies the
// 16 bytes at a0+96 to a0+16, unless the two addresses are equal (beql to the epilogue).
// Matching: s0 = a0 kept in $16 and reused as the destination (s0 + 16). The two
// addresses are kept opaque with empty asm barriers so gcc does not drop the guard. The
// 16-byte copy is an asm pair (lq/sq through $8) so the temp register is $8 as in the
// original. Frame is 16 bytes (s0, ra), no padding issue (72 bytes).
void func_0013fec0(u8* a0) {
    u32 s0 = (u32)a0;
    f32 f = func_0013fd10(a0);
    *(f32*)(s0 + 80) = f;
    func_0013fd78(a0);
    u32 q = s0 + 96;
    asm volatile("" : "+r"(q));
    s0 = s0 + 16;
    asm volatile("" : "+r"(s0));
    if (s0 != q) {
        asm volatile("lq $8,0(%0)\n\tsq $8,0(%1)" : : "r"(q), "r"(s0) : "$8", "memory");
    }
}

// FUN_00140760 (108 bytes)
// Code: FUN_0013f5f0(a0). s1 = FUN_00167f18(0). obj = a0->+68, fn = *(obj->vtable + 64),
// v = fn(obj). If v != 0, tail-calls FUN_00140618(a0, s1). Otherwise returns 0.
// Matching: plain C. The indirect call goes through a typed pointer loaded from the
// vtable, and the non-zero path is a tail call. The trailing padding of a 108-byte
// function needs -falign-functions=1, which the Makefile sets for this object.
u32 func_00140760(u8* a0) {
    func_0013f5f0(a0);
    u32 s1 = func_00167f18(0);
    u32 a4 = *(u32*)(a0 + 68);
    u32 t7 = *(u32*)a4;
    typedef u32 (*vfn0_t)(u32);
    vfn0_t fn = *(vfn0_t*)(t7 + 64);
    u32 v0 = fn(a4);
    if (v0 != 0) {
        return func_00140618(a0, s1);
    }
    return 0;
}
