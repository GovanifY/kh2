#pragma once

#include "../common/types.h"

namespace Tz {

struct SelectLayout {
    s16 current;
    char _pad0[2];
    s16 itemMax;
    char _pad1[12];
    s16 selectTop;
    char _pad2[12];
    u32 selectDisable;
    char _pad3[4];
    void** itemPtr;
    char _pad4[8];
    s32 enableButton;
};

class Select {
public:
    s16 GetCurrent();
    s32 GetLast();
    void* GetItemPtr(s32);
    void* GetCurrentItemPtr();
    s16 GetItemMax();
    s16 GetSelectMax();
    u32 isFadeOut();
    u32 isCursorMove();
    s32 GetEnableButton();
    s16 GetSelectTop();
    s32 SetEnableButton(u32);
    s32 SetDisableButton(u32);
    void SetSelectorLoop(bool);
    s32 SetEnableShortCut(u32 v);
    void SetSelectDisable(u32 v);
};

}  // namespace Tz

