#include "types.h"

namespace Tz {

class ScrollBar {
public:
    static void FadeOut();
};

class CmItem {
public:
    static void FadeOutAll();
    static void LeaveAll();
};

class CmTop {
public:
    static void FadeOutPadHelp();
    static s32 GetSelectPos(s32);
};

extern "C" u32 func_00287bc0();
extern "C" u32 func_00287db0();
extern "C" void func_00256ea8(...);
extern "C" void func_002620a0();
extern "C" void func_002621a0();
extern "C" void func_00262c40();
extern "C" void func_00262fa0();
extern "C" void func_00281b30();
extern "C" void func_00262118();
extern "C" void func_00262208();
extern "C" void func_00262588();
extern "C" void func_00262cb8();
extern "C" void func_00262ff8();
extern "C" void func_00281c50();

void CmItem::FadeOutAll() {
    u32 v0 = func_00287bc0();
    if (v0 != 1 && v0 != 10 && v0 != 11 && v0 != 12 && v0 != 13 && v0 != 14) {
        return;
    }
    func_002620a0();
    func_002621a0();
    ScrollBar::FadeOut();
    func_00262c40();
    func_00262fa0();
    func_00281b30();
    if (func_00287db0() != 0) {
        CmTop::FadeOutPadHelp();
    }
}

void CmItem::LeaveAll() {
    u32 v0 = func_00287bc0();
    if (v0 != 1 && v0 != 10 && v0 != 11 && v0 != 12 && v0 != 13 && v0 != 14) {
        return;
    }
    func_00262118();
    func_00262208();
    func_00262588();
    func_00262cb8();
    func_00262ff8();
    func_00281c50();
    func_00256ea8();
}

}  // namespace Tz
