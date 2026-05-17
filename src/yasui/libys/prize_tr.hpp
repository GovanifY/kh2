#pragma once

#include "../../common/types.h"

class BTLOBJ;
class FVector;
class OBJENTRY;
class PRIZE_TR;

namespace YS {

    class PRIZE_TR {
    public:
     PRIZE_TR(PRIZE_TR* a0, OBJENTRY* a1);
     void AppearNum(FVector* a0, s32 a1);
     void GetAll(BTLOBJ* a0);
    };

}  // namespace YS

