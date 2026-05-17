#pragma once

#include "../../common/types.h"

class FVector;
class UNIT_DATA_ZONE;
class ZONE;

namespace YS {

    class ZONE {
    public:
     ZONE(ZONE* a0, UNIT_DATA_ZONE* a1);
     void calc_rtn_action_point(FVector* a0);
     u64 is_jump(s32 a0);
     ~ZONE();
     u32 draw(u32 a0);
    };

}  // namespace YS

