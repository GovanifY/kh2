#pragma once

#include "../../common/types.h"

class OBJ;

namespace YS {

    class PRIORITYTARGET {
    public:
     void clear(void);
     void set(s32 a0, OBJ* a1);
     s32 search(void);
    };

}  // namespace YS

