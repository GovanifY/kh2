#pragma once

#include "../../common/types.h"
#include "../../common/task.hpp"

class DAMAGE;
class OBJ;

namespace YS {

    class UNITSCRIPT {
    public:
     void ExecTask(TASK* a0);
     void Stop(s32 a0);
     void Finalizer(TASK* a0);
     void Init(void);
     u64 Start(void* a0);
     void Signal(s32 a0, s32 a1);
     void DamageCallback(OBJ* a0, DAMAGE* a1);
    };

}  // namespace YS

