#pragma once

#include "../common/types.h"

class Info;
struct TASK;

namespace Tz {

class ChgWeapon {
public:
    void LoadWeaponThread(TASK* a0);
    void ResetPause(void);
    void Init(void);
    void Exit(void);
    void Set(s32 a0, s32 a1, s32 a2, Info* a3);
    void SetOrg(s32 a0, s32 a1, s32 a2);
    void Update(void);
    u64 isExist(void);
    void SetPause(void);
    u64 isPause(void);
};

}  // namespace Tz

