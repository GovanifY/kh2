#pragma once

#include "../../common/types.h"

class FVector;
class VACUUM;

namespace YS {

    class VACUUM {
    public:
     VACUUM(VACUUM* a0, FVector* a1, f32 a2);
     ~VACUUM();
     void Init(void);
     void Exit(void);
    };

}  // namespace YS

