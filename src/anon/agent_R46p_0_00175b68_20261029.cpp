#include "../common/types.h"

// Agent R46p_0 (2026-10-29): FUN_00175b68 (80 bytes, SLPM_666.75).

typedef int u128 __attribute__((mode(TI)));

extern "C" void func_0016b010(u8* a0, u128* a1);
extern "C" void func_00198690(u8* a0);

// FUN_00175b68: calls the virtual slot at +132 of the vtable of arg0 with arg0. If it returns non-zero,
// copies the 16 bytes at arg0+16 to a local buffer and calls func_0016b010(arg0, &buf). Then calls
// func_00198690(arg0) and returns (the epilogue follows).
void func_00175b68(u8* a0) {
    u128 buf;
    typedef s32 (*VFn)(u8*);
    u32* vt = *(u32**)a0;
    VFn f = (VFn)vt[33];
    register u8* obj asm("$16");
    obj = a0;
    s32 r = f(obj);
    if (r != 0) {
        register u8* src asm("$15");
        src = obj + 16;
        asm volatile("" : "+r"(src));
        register u128 tmp asm("$8");
        tmp = *(u128*)src;
        buf = tmp;
        asm volatile("" : "+r"(obj));
        func_0016b010(obj, &buf);
    }
    func_00198690(obj);
}
