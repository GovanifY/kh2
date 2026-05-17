#pragma once

#include "../../common/types.h"

class FVector;
class OBJENTRY;
class PARTY;
class TREASURE_BOX;

namespace YS {

    class TREASURE_BOX {
    public:
     void _OVR_initialize(void);
     TREASURE_BOX(TREASURE_BOX* a0, OBJENTRY* a1, FVector* a2, f32 a3);
     void open(PARTY* a0);
    };

}  // namespace YS

