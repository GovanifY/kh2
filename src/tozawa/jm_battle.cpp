#include "types.h"

namespace Tz {

extern "C" u32 func_00287bc0();
extern "C" void func_002a67a8();
extern "C" void func_00274ac8() asm("_ZN2Tz6Jiminy13JmCommonLeaveEv");

class JmBattle {
public:
    static void LeaveAll();
};

void JmBattle::LeaveAll() {
    if ((u32)(func_00287bc0() - 37u) < 2u) {
        func_002a67a8();
        func_00274ac8();
    }
}

}  // namespace Tz
