#include "types.h"

namespace Tz {

class JmStory {
public:
    static u32 Init();
    static void LeaveAll();
};

extern "C" u32 func_00103570();
extern "C" u32 func_001063c0(u32, u32);
extern "C" u32 func_00287bc0();
extern "C" void func_00274ac8() asm("_ZN2Tz6Jiminy13JmCommonLeaveEv");
extern "C" void func_0028f7e8(...);
extern u32 D_0035f594 asm("D_0035f594");

u32 JmStory::Init() {
    u32 r2 = func_00103570();
    r2 = func_001063c0(520, r2);
    D_0035f594 = r2;
    return r2;
}

void JmStory::LeaveAll() {
    if (func_00287bc0() == 3) {
        func_00274ac8();
        func_0028f7e8(0);
    }
}

}  // namespace Tz
