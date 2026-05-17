#pragma once

#include "../../common/types.h"

class OBJ;
class ObjCamera;

namespace dk {

    class CannonCamera {
    public:
     void update(ObjCamera* a0);
     s32 create(OBJ* a0);
    };

}  // namespace dk

