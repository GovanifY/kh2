#pragma once

#include "../../common/types.h"

class CROWDEFFECT;
class FVector;
class OBJENTRY;

namespace YS {

    class CROWD_M_EX760 {
    public:
     void _OVR_exec(void);
     u64 CheckAttack(CROWDEFFECT* a0);
     void ActionIdle(CROWDEFFECT* a0);
     void ActionLeave(CROWDEFFECT* a0);
     void ActionAppear(CROWDEFFECT* a0);
     void _ActionBlow(CROWDEFFECT* a0);
     void ActionBlow(CROWDEFFECT* a0);
     void ActionLastStage(CROWDEFFECT* a0);
     void ActionDead(CROWDEFFECT* a0);
     void Create(OBJENTRY* a0, FVector* a1, f32 a2);
    };

}  // namespace YS

