#include "jm_treasure.hpp"

namespace Tz {

extern "C" u32 func_001a3570(...);
extern "C" u32 func_00287bc0(...);
extern "C" void func_002a41f0(...);
extern "C" void func_00274ac8(...) asm("_ZN2Tz6Jiminy13JmCommonLeaveEv");

void JmTreasure::LeaveAll() {
    u32 v0 = func_00287bc0();
    if (v0 == 7 || v0 == 26 || v0 == 9 || v0 == 34 || v0 == 8 || v0 == 33) {
        func_002a41f0();
        func_00274ac8();
    }
}

u32 JmTreasure::isEnableNavi(YS::TREASURE::TABLE const* entry) {
    u32 r4 = (u32)(*(u16*)((u32)entry + (s32)(2)));
    u32 r2 = func_001a3570(r4);
    r2 = ((s32)0u < (s32)r2);
    return r2;
}

}  // namespace Tz
