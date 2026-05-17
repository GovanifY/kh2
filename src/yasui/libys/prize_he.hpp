#pragma once

#include "../../common/types.h"

class FVector;
class OBJENTRY;
class PRIZETABLE;
class PRIZE_HE;

namespace YS {

    class PRIZE_HE {
    public:
     PRIZE_HE(PRIZE_HE* a0, OBJENTRY* a1);
     void AppearTable(FVector* a0, PRIZETABLE* a1);
    };

}  // namespace YS

