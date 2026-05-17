#pragma once

#include "../../common/types.h"

class FuncDef64;
class FuncDef65;
class MOTION;
class OBJ;
class TRIGGER;

namespace YS {

    class ANMATR {
    public:
     void TriggerEffect(MOTION* a0, TRIGGER* a1);
     void ReactionCommand(OBJ* a0, s32 a1, s32 a2);
     void ExecTriggerCallback(TRIGGER* a0, void* a1);
     void each_range(f32 a0, FuncDef64* a1, void* a2);
     void check_range(MOTION* a0, f32 a1);
     void each_trigger(f32 a0, f32 a1, FuncDef65* a2, void* a3);
     void exec_trigger(MOTION* a0, f32 a1, f32 a2);
     void Reset(MOTION* a0);
    };

}  // namespace YS

