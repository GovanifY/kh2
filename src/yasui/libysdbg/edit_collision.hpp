#pragma once

#include "../../common/types.h"

class EDIT_COLLISION;

namespace YS {

    class EDIT_COLLISION {
    public:
     void idle_func(void);
     void Init(void);
     void Open(s32 a0);
     ~EDIT_COLLISION();
    };

}  // namespace YS

