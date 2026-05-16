#include "types.h"

namespace Tz {

extern u16 D_00374770[] asm("D_00374770");
extern u32 D_0035f200 asm("D_0035f200");
extern "C" u32 func_00287bc0();
extern "C" u32 func_0028b040(u32);
extern "C" u32 func_00296da8(u32);
extern "C" void func_00276c50(u32, u32);

class Select;

class JmReport {
public:
    static void DrawUpdate(Select*, s32, s32);
};

void JmReport::DrawUpdate(Select*, s32, s32) {
    u32 a0 = 0;
    u32 v0 = func_00287bc0();
    if (v0 == 1) {
        goto special;
    }
    v0 = func_0028b040(D_0035f200);
    v0 = func_00296da8(v0);
    v0 <<= 1;
    v0 = (u32)(((u8*)D_00374770) + v0);
    a0 = *(u16*)v0;
    goto call;
special:
    a0 = 18751;
call:
    func_00276c50(a0, 0);
}

}  // namespace Tz
