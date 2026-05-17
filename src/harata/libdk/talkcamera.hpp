#pragma once

#include "../../common/types.h"
#include "../../common/task.hpp"

class ObjCamera;

namespace dk {

    class TalkCamera {
    public:
     void calcCamera(ObjCamera* a0);
     void update(ObjCamera* a0);
     void ensureTask(TASK* a0);
    };

}  // namespace dk

