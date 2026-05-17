#ifndef KH2_SRC_TOZAWA_JM_WORLDSEL_HPP
#define KH2_SRC_TOZAWA_JM_WORLDSEL_HPP

#include "../common/types.h"

namespace Tz {

class Select;

class JmWorldSel {
public:
    s64 AdjustSelectorPos(void);
    void FileAlloc(void);
    void CreateGra(bool a0);
    s32 GetCur2Idx(s32 a0);
    s32 GetId2CurPos(s32 a0);
    void UpdateWorldName(void);
    u64 SelCheck(s32 a0);
    void Init(void);
    void Exit(void);
    void FadeOutAll(void);
    void LeaveAll(void);
    void Setup(void);
    void Control(void);
    s32 GetId2Info(s32 a0);
    u16 GetId2WorldName(s32 a0, bool a1);
    void isWorldOpen(s32 a0);
    void DrawUpdate(Select* a0, s32 a1, s32 a2);
};

}  // namespace Tz

#endif
