#ifndef KH2_SRC_TOZAWA_JM_MINIGAME_HPP
#define KH2_SRC_TOZAWA_JM_MINIGAME_HPP

#include "types.h"

namespace Tz {

class Select;

class JmMiniGame {
public:
    void AdjustPos(void);
    void ChkMGameInfo(void);
    void CreateList(void);
    u64 isPlay(s32 a0);
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

#endif
