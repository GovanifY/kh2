#pragma once

#include "../../common/types.h"

class FVector;
class OBJENTRY;
class SAVEPOINT;

namespace YS {

    class SAVEPOINT {
    public:
     SAVEPOINT(SAVEPOINT* a0, OBJENTRY* a1, FVector* a2, f32 a3);
     u64 initialize(OBJENTRY* a0, FVector* a1, f32 a2);
     void EffectOff(void);
     void recover(void);
    };

}  // namespace YS

