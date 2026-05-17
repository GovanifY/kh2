#pragma once

#include "../../common/types.h"

class FVector;
class Sky;

namespace dk {

    class Sky {
    public:
     Sky(Sky* a0, u32 a1, FVector* a2, FVector* a3, FVector* a4, s32 a5, s32 a6);
     void draw(void);
     ~Sky();
    };

}  // namespace dk

