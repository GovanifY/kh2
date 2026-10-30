#include "../common/types.h"

extern "C" void func_002e70b0(u32 a0);
extern "C" void func_00106420(u32 a0);
extern "C" void func_002cea28(u32 a0);

extern u8 D_00360000;

// FUN_002d72e0 (88 bytes). Stores the vtable D_00360000+9640 at a0, calls func_002e70b0 and
// func_00106420 on the sub-object at +160 when it is non-null, then calls func_002cea28(a0).
void func_002d72e0(u32 a0) {
    *(u32*)a0 = (u32)&D_00360000 + 9640u;
    u32 s = *(u32*)(a0 + 160);
    if (s != 0) {
        func_002e70b0(s);
        func_00106420(s);
    }
    func_002cea28(a0);
    asm volatile("" ::: "memory");
}
