#pragma once

#include "../../common/types.h"
#include "../../common/task.hpp"


namespace dk {

class Camera {
public:
    void setNoKick();
    void after1CameraTask(TASK*);
    void multiAfter2CameraTask(TASK*);
};

}  // namespace dk

