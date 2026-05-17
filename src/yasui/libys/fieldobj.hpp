#pragma once

#include "../../common/types.h"

class FIELDOBJ;
class FVector;
class OBJENTRY;

namespace YS {

    class FIELDOBJ {
    public:
     FIELDOBJ(FIELDOBJ* a0, OBJENTRY* a1, FVector* a2, f32 a3);
     void mark_history(void);
     void is_mark_history(void);
    };

}  // namespace YS

