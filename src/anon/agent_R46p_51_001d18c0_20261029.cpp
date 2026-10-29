#include "../common/types.h"

// FUN_001d18c0 (76 bytes).
// Code: calls YS::MISSION2D::activate(this) (mangled, 0x1d16f8). If this->+4 is non-zero, calls
// func_0014f688(+4, +8, +32, +36, +28). Then tail-calls func_001d1950(this, this->+20).
extern s32 YS_MISSION2D_activate(void *) asm("_ZN2YS9MISSION2D8activateEv");
extern void func_0014f688(u32, u32, u32, u32, u32);
extern s32 func_001d1950(void *, u32);

s32 func_001d18c0(void *self) {
    u8 *s = (u8 *)self;
    YS_MISSION2D_activate(self);
    if (*(u32 *)(s + 4) != 0) {
        func_0014f688(*(u32 *)(s + 4), *(u32 *)(s + 8), *(u32 *)(s + 32), *(u32 *)(s + 36),
                      *(u32 *)(s + 28));
    }
    return func_001d1950(self, *(u32 *)(s + 20));
}
