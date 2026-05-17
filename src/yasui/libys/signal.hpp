#pragma once

#include "../../common/types.h"
#include "../../common/task.hpp"

class OBJ;

namespace YS {

    class SIGNAL {
    public:
     void ClearReserve(s32 a0);
     u64 Call(s32 a0, s32 a1);
     void Exec(TASK* a0);
     void Init(void);
     void ReserveHp(OBJ* a0, f32 a1, s32 a2, s32 a3);
     void ReserveMinHp(OBJ* a0, s32 a1, s32 a2);
    };

}  // namespace YS

