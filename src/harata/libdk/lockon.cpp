#include "types.h"

namespace dk {

extern void Obj2D_showGroup(s32) asm("_ZN2dk5Obj2D9showGroupEi");

class LockOn {
public:
    static void* getYIImage();
    void show();
};

extern u32 D_003486a0 asm("D_003486a0");

void* LockOn::getYIImage() {
    u32 p = D_003486a0;
    return (void*)((s32)p + 32);
}

void LockOn::show() { Obj2D_showGroup(0x11); }

}  // namespace dk
