#pragma once

#include "../common/types.h"

namespace Tz {

class JmQuestDataInfo;
class Select;

class JmQuest {
public:
    void AdjustPos(void);
    u64 GetQuestStat(JmQuestDataInfo* a0);
    void ChkQuestInfo(void);
    void CreateList(void);
    void UpdateList(void);
    void UpdateNewMark(void);
    void Init(void);
    void Exit(void);
    void FadeOutAll(void);
    void LeaveAll(void);
    void Setup(void);
    void Control(void);
    void DrawUpdate(Select* a0, s32 a1, s32 a2);
    bool isEnable(s32 a0);
};

}  // namespace Tz

