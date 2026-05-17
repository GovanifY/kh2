#pragma once

#include "../../common/types.h"

class ObjCamera;

namespace dk {

    class LightCycleCamera {
    public:
     void update(ObjCamera* a0);
     s32 create(void);
    };

}  // namespace dk

