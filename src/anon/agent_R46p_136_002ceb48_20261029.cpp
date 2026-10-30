#include "../common/types.h"

// Agent R46p_136: FUN_002ceb48 (104 bytes). Frees a cached child, then calls vtable slot 1 of the global object.
extern u8 D_00360000;
void func_00170950(void* p) asm("func_00170950");

#define G_OBJ (*(void**)((u8*)&D_00360000 + 8032))

void r_FUN_002ceb48(void) asm("func_002ceb48");
void r_FUN_002ceb48(void) {
    void* t = G_OBJ;
    if (t == 0) return;
    void* f = *(void**)((u8*)t + 96);
    if (f != 0) {
        func_00170950(f);
        *(void**)((u8*)G_OBJ + 96) = 0;
        t = G_OBJ;
    }
    if (t != 0) {
        void** vt = *(void***)t;
        ((void (*)(void*))vt[1])(t);
    }
    G_OBJ = 0;
}
