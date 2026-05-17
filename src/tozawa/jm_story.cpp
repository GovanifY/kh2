#include "cmenu_slbase.hpp"
#include "jm_story.hpp"

namespace Tz {

u32 LoadDataGetSystem();
u32 LoadDataAlloc(u32, u32);
extern "C" void func_00274ac8() asm("_ZN2Tz6Jiminy13JmCommonLeaveEv");
extern u32 D_0035f594 asm("D_0035f594");

u32 JmStory::Init() {
    u32 r2 = LoadDataGetSystem();
    r2 = LoadDataAlloc(520, r2);
    D_0035f594 = r2;
    return r2;
}

void JmStory::LeaveAll() {
    if (MenuBase::GetMode() == 3) {
        func_00274ac8();
        LeaveAllPost(0);
    }
}

}  // namespace Tz
