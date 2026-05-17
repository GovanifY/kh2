#ifndef KH2_SRC_TOZAWA_SELECT_HPP
#define KH2_SRC_TOZAWA_SELECT_HPP

#include "../common/types.h"

namespace Tz {

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

#endif
