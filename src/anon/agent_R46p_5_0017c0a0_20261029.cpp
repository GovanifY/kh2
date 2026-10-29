#include "../common/types.h"

// FUN_0017c0a0 (104 bytes): builds a 16-byte record through FUN_0017c030 (out = stack, a2 = &int, a3 = a2 & 0xff),
// copies the record to a second stack buffer with lq/sq, calls FUN_0017c4c8(obj, buf), then FUN_0017f488(obj+320, int, 0.0f, 0.0f),
// and sets obj+260 = 5, obj+256 = 4.
extern "C" void func_0017c030(u32 out, u32 obj, u32 tmp, u32 flag);
extern "C" void func_0017c4c8(u32 obj, u32 buf);
extern "C" void func_0017f488(u32 p, u32 v, float f12, float f13);

void func_0017c0a0(u32 a0, u32 a1, u32 a2) {
    u32 src[4] __attribute__((aligned(16)));
    u32 dst[4] __attribute__((aligned(16)));
    u32 tmp;
    func_0017c030((u32)src, a1, (u32)&tmp, a2 & 0xff);
    asm volatile("lq $8,0(%0)\n\tsq $8,0(%1)" : : "r"(src), "r"(dst) : "$8", "memory");
    func_0017c4c8(a1, (u32)dst);
    func_0017f488(a1 + 320, tmp, 0.0f, 0.0f);
    register u32 v5 asm("$15") = 5;
    register u32 v4 asm("$14") = 4;
    *(u32 *)(a1 + 260) = v5;
    *(u32 *)(a1 + 256) = v4;
}
