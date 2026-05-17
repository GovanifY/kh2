#pragma once

#include "../../common/types.h"

class FVector;
class MASSOBJ;
class OBJENTRY;

namespace YS {

    class MASSOBJ {
    public:
     void _OVR_exec(void);
     void _OVR_leave_req(void);
     MASSOBJ(MASSOBJ* a0, OBJENTRY* a1, s32 a2, s32 a3, s32 a4, u32 a5, u32 a6);
     u64 Create(OBJENTRY* a0, FVector* a1, f32 a2);
    };

}  // namespace YS

