#include "../common/types.h"

// Agent R46p_65 (2026-10-29): FUN_001db7d0 (56 bytes), SLPM_666.75.
// Stores the vtable word 0x352a38 at +0, then calls the slot at vtable+4 of the object
// stored at +4, passing that object and the word at +12.
void func_001db7d0(u32 *p) {
    register u32 *obj asm("$13");
    register u32 *vt asm("$15");
    register void (*fn)(u32*, u32) asm("$14");
    u32 base = 0x350000;
    u32 arg;
    asm volatile("" : "+r"(base));
    p[0] = base + 10808;
    asm volatile("" ::: "memory");
    obj = (u32*)p[1];
    arg = p[3];
    vt = (u32*)obj[0];
    fn = (void (*)(u32*, u32))vt[1];
    fn(obj, arg);
}
