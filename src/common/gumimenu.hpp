#pragma once

#include "./types.h"
#include "task.hpp"

class CAMERA;
class FuncDef11;
class FuncDef12;

namespace gm {

    class GUMI_MENU {
    public:
     void ensure(void);
     void SetGumiMenuHelpMessage(s32 a0);
     void packet_kick(TASK* a0);
     void packet_close(TASK* a0);
     void draw_queue_flush(TASK* a0);
     void vu1draw_wait(TASK* a0);
     void startMenuBgm(void);
     void startEditBgm(void);
     void startSortieBgm(void);
     void CreateGumiMenuBGObj(CAMERA* a0);
     void init(TASK* a0);
     void thread_main(TASK* a0);
     u32 GetGumiMenuBGObj(void);
     u32 GetTaskManager(void);
     u64 IsTinySystemExist(void);
    };

}  // namespace gm

