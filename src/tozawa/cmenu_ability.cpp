#include "cmenu_ability.hpp"

namespace Tz {

extern "C" u32 getSaveRam() asm("_Z10getSaveRamv");

extern "C" u32 func_0027bba0(u32);

u32 CmAbility::GetItemTbl(s32 index) {
    u32 r2 = func_0027bba0((u32)index);
    r2 = (u32)(*(u8*)((u32)r2 + (s32)(6)));
    r2 = (u32)(r2 ^ 0x0001u);
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}

u32 CmAbility::isWorldLK() {
    u32 r2 = getSaveRam();
    r2 = (u32)(*(u8*)((u32)r2 + 12));
    r2 = (u32)(r2 ^ 0x000au);
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}

extern "C" u32 func_00287bc0();
extern "C" void func_0027a180();
extern "C" void func_0027a898(u32);
extern "C" void func_0027acf8();
extern "C" void func_00256ea8();

void CmAbility::LeaveAll() {
    if ((u32)(func_00287bc0() - 15u) >= 5u) {
        return;
    }
    func_0027a180();
    func_0027a898(1u);
    func_0027acf8();
    func_00256ea8();
}

}  // namespace Tz
