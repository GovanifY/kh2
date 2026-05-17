#pragma once

#include "../../common/types.h"

class FVector;
class JIGSAWPIECE;
class OBJENTRY;

namespace YS {

    class JIGSAWPIECE {
    public:
     void _OVR_initialize(void);
     void _OVR_exec(void);
     JIGSAWPIECE(JIGSAWPIECE* a0, OBJENTRY* a1, FVector* a2, f32 a3);
    };

}  // namespace YS

