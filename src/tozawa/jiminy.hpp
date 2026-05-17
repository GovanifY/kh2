#pragma once

#include "../common/types.h"

namespace dk {
class Sprite;
}

struct ALLOCATOR;

namespace Tz {

class Select;

class Jiminy {
public:
    static void DrawSelector(Select*, s32, s32);
    static void JmCommonLeave();
    static void CreateLightCursor(::dk::Sprite*);
    static void SetupMainFrame();
    static u32 GetAccomplishmentRate();
    static u32 WMRead();
    static u32 WMExit();
    static void WMInit(ALLOCATOR*);
    static void InitWorldNo(s32);
    static void SetCover(s32);
    static void SetHideCursor(bool);
    static void SetHideLightCursor(bool);
    static void SaveCurPos(s32, s32, s32);
    static void* GetParent();
    static s32 GetParentAnimMode();
    static void* GetMenuInfo();
    static s32 GetCurPos(s32);
    static s32 GetCurTopPos(s32);
    static s32 GetSelectPos(s32);
    static void* GetSeqTbl();
    static void* GetScrBarSeqTbl();
    static s32 GetFontColorSeqNum(s32);
};

}  // namespace Tz

