#pragma once

#include "../../common/types.h"

class CROWDEFFECT;
class CROWDOBJ;
class CROWD_EVENT;
class FVector;
class OBJENTRY;

namespace YS {

    class CROWD_EVENT {
    public:
     void _OVR_leave_req(void);
     CROWD_EVENT(CROWD_EVENT* a0, CROWDOBJ* a1, OBJENTRY* a2, FVector* a3, f32 a4);
     void ActionIdle(CROWDEFFECT* a0);
     void _OVR_appear(FVector* a0, s32 a1);
     u64 Create(OBJENTRY* a0, FVector* a1, f32 a2);
    };

}  // namespace YS

