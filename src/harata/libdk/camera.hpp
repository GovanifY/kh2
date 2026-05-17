#pragma once

#include "../../common/types.h"

struct TASK;

namespace dk {

class Camera {
public:
    void setNoKick();
    void after1CameraTask(TASK*);
    void multiAfter2CameraTask(TASK*);
};

}  // namespace dk

