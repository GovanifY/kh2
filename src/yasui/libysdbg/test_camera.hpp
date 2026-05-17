#pragma once

#include "../../common/types.h"
#include "../../common/task.hpp"

class OBJ;

namespace YS {

    class TEST_CAMERA {
    public:
     void ExecTask(TASK* a0);
     void Start(OBJ* a0);
     void Stop(void);
    };

}  // namespace YS

