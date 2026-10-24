#include "../common/types.h"

// Agent R46m_11: FUN_00173808 (52 bytes), SLPM_666.75.
// Copies the 16-byte block at the pointer stored at a0+4 into a 16-byte stack buffer, then calls
// FUN_0019fdc0(word at (word at a0) + 4, buffer, float at a0+8).
// Register pins: src in t7, the object pointer in t6, the 128-bit temporary in t0, the float in $f12.
extern "C" void func_0019fdc0(u32, void*, f32);

typedef int u128 __attribute__((mode(TI)));

void func_00173808(u8* a0) {
    register u8* src asm("$15");
    register u8* obj asm("$14");
    register u128 tmp asm("$8");
    register f32 fv asm("$f12");
    register u8* bp asm("$5");
    u8 buf[16];

    src = *(u8**)(a0 + 4);
    asm volatile("" : "+r"(src));
    tmp = *(u128*)src;
    asm volatile("" ::: "memory");
    *(u128*)buf = tmp;
    obj = *(u8**)a0;
    asm volatile("" : "+r"(obj));
    bp = buf;
    asm volatile("" : "+r"(bp));
    fv = *(f32*)(a0 + 8);
    asm volatile("" : "+f"(fv));
    func_0019fdc0(*(u32*)(obj + 4), bp, fv);
}
