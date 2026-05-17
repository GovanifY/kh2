#pragma once

#include "../common/types.h"

namespace worldmap {

class Camera {
public:
    u64 update();
    void sleep();
    void initialize();
    ~Camera();
};

}  // namespace worldmap

