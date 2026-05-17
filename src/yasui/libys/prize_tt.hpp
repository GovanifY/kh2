#pragma once

#include "../../common/types.h"

class DAMAGE;
class OBJENTRY;
class PRIZEEFFECT;
class PRIZE_TT;

namespace YS {

    class PRIZE_TT {
    public:
     void _OVR_check_get(PRIZEEFFECT* a0);
     PRIZE_TT(PRIZE_TT* a0, OBJENTRY* a1);
     void ExecDamage(DAMAGE* a0);
    };

}  // namespace YS

