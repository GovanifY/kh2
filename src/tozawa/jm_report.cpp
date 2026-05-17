#include "cmenu_slbase.hpp"
#include "jm_report.hpp"

namespace Tz {

extern u16 D_00374770[] asm("D_00374770");
extern u32 D_0035f200 asm("D_0035f200");
void JmReport::DrawUpdate(Select*, s32, s32) {
    u32 a0 = 0;
    u32 v0 = (u32)MenuBase::GetMode();
    if (v0 == 1) {
        goto special;
    }
    v0 = GetData(D_0035f200);
    v0 = GetIndex(v0);
    v0 <<= 1;
    v0 = (u32)(((u8*)D_00374770) + v0);
    a0 = *(u16*)v0;
    goto call;
special:
    a0 = 18751;
call:
    DrawMessage(a0, 0);
}

}  // namespace Tz
