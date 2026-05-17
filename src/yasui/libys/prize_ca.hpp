#pragma once

#include "../../common/types.h"

class BTLOBJ;
class FVector;
class MASSEFFECT;
class OBJENTRY;
class PRIZEEFFECT;
class PRIZE_CA;

namespace YS {

    class PRIZE_CA {
    public:
     void _OVR_check_get(PRIZEEFFECT* a0);
     PRIZE_CA(PRIZE_CA* a0, OBJENTRY* a1);
     void Appear(BTLOBJ* a0, s32 a1);
     void InitAppear(FVector* a0, s32 a1);
     u64 Return(BTLOBJ* a0, BTLOBJ* a1, s32 a2);
     u64 Vacuum(BTLOBJ* a0, BTLOBJ* a1, s32 a2);
     void VacuumRange(BTLOBJ* a0, f32 a1);
     u32 GetAppearNum(void);
     void PhaseVacuum(MASSEFFECT* a0);
     bool PhaseReturn(MASSEFFECT* a0);
    };

}  // namespace YS

