#pragma once

#include "../../common/types.h"
#include "../../common/task.hpp"

class COMMAND_ELEM;
class FRIEND;

namespace YS {

    class SACRIFICE {
    public:
     s32 Return(s32 a0);
     u64 CanSummon(void);
     void Init(void);
     void StartPart(s32 a0, f32 a1);
     void Start(FRIEND* a0, f32 a1);
     u64 CheckForm(s32 a0, s32 a1);
     void StartForm(s32 a0);
     void StartAll(f32 a0);
     u64 CanEnd(void);
     void End(void);
     s32 GetFormStatus(s32 a0);
     u64 GetCommandStatus(COMMAND_ELEM* a0);
     u64 IsSacrifice(s32 a0);
     u64 IsExec(void);
     void WaitStable(TASK* a0);
    };

}  // namespace YS

