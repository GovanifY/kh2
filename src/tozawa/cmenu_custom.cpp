#include "types.h"

namespace Tz {

extern u32 D_0035f12c asm("D_0035f12c");

class CmCustom {
public:
    static u32 GetItemTbl(s32);
    static void LeaveAll();
};

extern "C" u32 func_001a80c8(...);

u32 CmCustom::GetItemTbl(s32 index) {
    u32 p = ((u32)index << 3) + D_0035f12c;
    s32 v = *(s16*)(p + 8u);
    if (v != 0) {
        return func_001a80c8((u32)v);
    }
    return 0u;
}

extern "C" u32 func_00287bc0();
extern "C" void func_00271e80();
extern "C" void func_002723e0();
extern "C" void func_00256ea8();

void CmCustom::LeaveAll() {
    if ((u32)(func_00287bc0() - 25u) >= 9u) {
        return;
    }
    func_00271e80();
    func_002723e0();
    func_00256ea8();
}

}  // namespace Tz
