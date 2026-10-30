#include "../common/types.h"
extern u8 D_00360000;
#define G_OBJ (*(void**)((u8*)&D_00360000 + 8032))
u32 r_FUN_002cebc8(void* a0) asm("func_002cebc8");
u32 r_FUN_002cebc8(void* a0) {
    void* g = G_OBJ;
    u32 res;
    if (g != 0) {
        void** vt = *(void***)g;
        res = ((u32 (*)(void*, void*))vt[4])(g, a0);
    } else {
        res = 0;
    }
    return res;
}
