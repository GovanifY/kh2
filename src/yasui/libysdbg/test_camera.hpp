#pragma once

#include "../../common/types.h"

class OBJ;
struct TASK;

namespace YS {

    class TEST_CAMERA {
    public:
     void ExecTask(TASK* a0);
     void Start(OBJ* a0);
     void Stop(void);
    };

}  // namespace YS

