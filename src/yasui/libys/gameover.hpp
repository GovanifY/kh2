#pragma once

#include "../../common/types.h"

class GAMEOVER;
class OBJ;
class PLAYER;
struct TASK;

namespace YS {

    class GAMEOVER {
    public:
     void setup(void);
     void check_mickey(void);
     GAMEOVER(GAMEOVER* a0, OBJ* a1, s32 a2);
     ~GAMEOVER();
     u32 get_motion(u32 a0);
     void Reraise(void);
     u64 exec(void);
     void ExecTask(TASK* a0);
     void SelectorMickeyCallback(s32 a0, TASK* a1);
     void SelectorGameOverCallback(s32 a0, TASK* a1);
     s32 Start(PLAYER* a0);
     s32 MissionFailed(void);
     void TinkReraise(PLAYER* a0);
     void MiniGameFailed(PLAYER* a0);
     u64 IsExec(void);
     void Abort(void);
    };

}  // namespace YS

