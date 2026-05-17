#include "cmenu_slbase.hpp"
#include "jm_battle.hpp"

namespace Tz {

extern "C" void func_00274ac8() asm("_ZN2Tz6Jiminy13JmCommonLeaveEv");

void JmBattle::LeaveAll() {
    if ((u32)(MenuBase::GetMode() - 37u) < 2u) {
        LeaveAllInner();
        func_00274ac8();
    }
}

}  // namespace Tz
