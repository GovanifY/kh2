#pragma once

#include "../../common/types.h"

class OBJ;
struct TASK;
class UNIT;

namespace YS {

    class UNIT {
    public:
     void activate(void);
     UNIT(UNIT* a0, u32 a1, void* a2, bool a3);
     void ExecTask(TASK* a0);
     void Init(void);
     void Exit(void);
     void Entry(u32 a0, bool a1);
     void EntryScript(void* a0);
     void ReadRequest(void);
     void ActivateAll(void);
     void Activate(char* a0);
     u64 GetPath(s32 a0);
     u64 GetPathByID(s32 a0);
     void SetPlayer(OBJ* a0);
     void InitMinigame(void);
    };

}  // namespace YS

