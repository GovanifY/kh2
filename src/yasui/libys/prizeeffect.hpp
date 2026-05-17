#pragma once

#include "../../common/types.h"

class BTLOBJ;
class FVector;
class FuncDef61;
class FuncDef62;
class MASSEFFECT;
class PARAM;
class PRIZEEFFECT;
class PRIZEOBJ;

namespace YS {

    class PRIZEEFFECT {
    public:
     u64 PhaseCaMove(MASSEFFECT* a0);
     void phase_ca_vacuum(void);
     void vacuum_ca(BTLOBJ* a0);
     PRIZEEFFECT(PRIZEEFFECT* a0, PRIZEOBJ* a1, PARAM* a2, FVector* a3, FuncDef61* a4);
     PRIZEEFFECT(PRIZEEFFECT* a0, PRIZEOBJ* a1, PARAM* a2, FVector* a3, FuncDef62* a4);
     bool phase_land(bool a0);
     void _phase_move(f32 a0);
     u64 phase_get(void);
     u64 phase_al_get(void);
     u64 can_get(BTLOBJ* a0, f32 a1, f32 a2);
     void get(BTLOBJ* a0, s32 a1);
     void Init(void);
     void PhaseMove(MASSEFFECT* a0);
     void PhaseLand(MASSEFFECT* a0);
     void PhaseGet(MASSEFFECT* a0);
     void PhaseAlGet(MASSEFFECT* a0);
    };

}  // namespace YS

