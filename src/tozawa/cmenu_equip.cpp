#include "types.h"

namespace Tz {

extern u32 D_00373788 asm("D_00373788");
extern void* D_0035f010 asm("D_0035f010");

class CmEquip {
public:
    static void* GetFormMsgTbl();
    static void FadeOutAll();
    static void LeaveAll();
};

class CmTop {
public:
    static void LeaveShortCutInfo();
    static void FadeOutPadHelp();
};

void* CmEquip::GetFormMsgTbl() { return &D_00373788; }

extern "C" u32 func_00287bc0();
extern "C" u32 func_00287db0();
extern "C" void func_00256ea8(...);
extern "C" void func_00269e20();
extern "C" void func_00269ef8();
extern "C" void func_00281b30();
extern "C" void func_00281c50();

void CmEquip::FadeOutAll() {
    u32 v = func_00287bc0();
    if (v == 2 || v == 5 || v == 6 || v == 7 || v == 8 || v == 9) {
        func_00269e20();
        CmTop::LeaveShortCutInfo();
        func_00281b30();
        if (func_00287db0() != 0) {
            CmTop::FadeOutPadHelp();
        }
    }
}

void CmEquip::LeaveAll() {
    u32 v = func_00287bc0();
    if (v == 2 || v == 5 || v == 6 || v == 7 || v == 8 || v == 9) {
        func_00269ef8();
        CmTop::LeaveShortCutInfo();
        func_00281c50();
        func_00256ea8();
    }
}

}  // namespace Tz
