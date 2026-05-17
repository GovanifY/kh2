#pragma once

#include "../../common/types.h"

struct TASK;

namespace dk {

class BGM {
public:
 void setVolume(s32 a0, s32 a1);
 void typeHold(int* a0);
 void typeChange(int* a0);
 void checkFieldBgm(TASK* a0);
 u64 areaRead(TASK* a0);
 void areaStart(void);
 void areaInit(void);
 void init(void);
 void fieldInit(void);
 void fieldExit(void);
 void setNumber(s32 a0, s32 a1);
 void setMemNumber(s32 a0, s32 a1);
 void GameOver(void);
 void Continue(void);
 ~BGM();
 void Init(void);
 void PlayStage(void);
 void Fadeout(f32 a0);
 void Ensure(void);
 void ensure(void);
 void play(s32 a0);
 void ExecThread(TASK* a0);
};

}  // namespace dk

