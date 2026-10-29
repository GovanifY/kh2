#include "../common/types.h"

extern "C" void func_00177638(u8* a0);

typedef void (*R46pVFn)(u8*);

// FUN_00177540 (104 bytes): walks two pointer slots at +2808 and +2812. Each non-null object gets its
// virtual slot at vtable+72 called with the object; then tail-calls FUN_00177638(a0).
void func_00177540(u8* a0) {
    u8** s0 = (u8**)(a0 + 2808);
    for (s32 s1 = 1; s1 >= 0; s1--) {
        u8* p = *s0;
        s0++;
        if (p != 0) {
            u8* vt = *(u8**)p;
            R46pVFn f = *(R46pVFn*)(vt + 72);
            f(p);
        }
    }
    func_00177638(a0);
}
