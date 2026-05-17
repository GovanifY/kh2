#pragma once

#include "../common/types.h"

namespace dk {
class Sprite;
}

namespace Tz {

struct VtblCmTopWarningWin {
    u32 _pad0[5];
    void (*fn20)(void*);
};

struct ObjCmTopWarningWin {
    VtblCmTopWarningWin* vtbl;
};

class CmTop {
public:
    static u32 ExitParty();
    static u32 isExistListAll();
    static dk::Sprite* GetBaseSprite(s32);
    static void CreateShortCutInfo(dk::Sprite*);
    static void LeaveShortCutInfo();
    static void FadeOutPadHelp();
    static void LoopPadHelp();
    static void LeavePadHelp();
    static void SetHideCursor(bool);
    static void DelCursor();
    static s32 GetCurPos(s32);
    static s32 GetCurTopPos(s32);
    static s32 GetSelectPos(s32);
    static void LoopWarningWin(s32);
    static void LeaveWarningWin();
    static u32 GetSram();
    static u16* GetTopSelSeqTbl();
    static void SetDelCursor(bool);
    static void* GetScrBarSeqTbl();
    static void* GetTopPlateSeqTbl(s32);
    static void* GetTopPlate2SeqTbl(s32);
    static void* GetPartyInfo();
    static void* GetItemInfo();
    static s32 GetFontColorSeqNum(s32);
    static void* GetListBuffer();
    static u32 GetTopBase() asm("_ZN2Tz5CmTop13GetListBufferEv");
    static u32 ExitPartyImpl(...);
    static u32 IsWarningEnabled(...);
};

}  // namespace Tz
