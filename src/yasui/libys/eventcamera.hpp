#pragma once

#include "../../common/types.h"

class OBJ;

namespace YS {

    class EVENT_CAMERA {
    public:
     void set_type(s32 a0, OBJ* a1);
     void make_matrix(void);
    };

}  // namespace YS

