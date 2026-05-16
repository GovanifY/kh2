#include "types.h"

namespace YS {

extern "C" u32 func_00181500(...);

class PROGRESS {
public:
    static u32 CanOpenCampMenu();
    static u32 CanDrive();
};

u32 PROGRESS::CanOpenCampMenu() {
    s32 s0 = 0u;
    if (func_00181500(2071u) == 0u) goto L1;
    if (func_00181500(2100u) == 0u) goto L0;
L1:
    s0 = 1u;
L0:
    return (u32)s0;
}

u32 PROGRESS::CanDrive() {
    s32 s0 = 0u;
    if (func_00181500(2071u) == 0u) goto L1;
    if (func_00181500(2218u) == 0u) goto L0;
L1:
    s0 = 1u;
L0:
    return (u32)s0;
}

}  // namespace YS
