#include "../common/types.h"

// FUN_0017a418 (100 bytes): if a1 == 1 call FUN_001d6ae0(obj->+2876), if a1 == 2 call FUN_001d6b40(obj->+2876),
// then store the low byte of a1 at obj+2916.
extern "C" void func_001d6ae0(u32 p);
extern "C" void func_001d6b40(u32 p);

void func_0017a418(u8 *a0, u32 a1) {
    if (a1 == 1) goto call1;
    if (a1 == 2) goto call2;
store:
    a0[2916] = (u8)a1;
    return;
call2:
    func_001d6b40(*(u32 *)(a0 + 2876));
    goto store;
call1:
    func_001d6ae0(*(u32 *)(a0 + 2876));
    goto store;
}
