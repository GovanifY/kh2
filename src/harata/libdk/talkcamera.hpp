#pragma once

#include "../../common/types.h"

class ObjCamera;
struct TASK;

namespace dk {

    class TalkCamera {
    public:
     void calcCamera(ObjCamera* a0);
     void update(ObjCamera* a0);
     void ensureTask(TASK* a0);
    };

}  // namespace dk

