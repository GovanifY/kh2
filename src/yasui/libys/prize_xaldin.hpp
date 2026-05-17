#pragma once

#include "../../common/types.h"

class FVector;
class OBJENTRY;
class PRIZE_XALDIN;

namespace YS {

    class PRIZE_XALDIN {
    public:
     PRIZE_XALDIN(PRIZE_XALDIN* a0, OBJENTRY* a1);
     void Appear(FVector* a0, s32 a1);
    };

}  // namespace YS

