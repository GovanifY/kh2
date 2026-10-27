#include "../common/types.h"

extern "C" void func_0016c568(u32 a0, u32 a1, f32 f);

// FUN_002f0948 (40 bytes): same shape as FUN_002e7c78; tail-calls FUN_0016c568 with fields of the object at a0.
void func_002f0948(u32* a0) {
    u32* t7 = (u32*)a0[0];
    f32 f = *(f32*)(a0 + 2);
    asm volatile("" : "+r"(t7));
    u32 t6 = t7[1];
    func_0016c568(t6, a0[1], f);
}
