#pragma once

#include "../common/types.h"

class FVector;
class TARGET;

namespace worldmap {

class CloseUpCamera {
public:
    ~CloseUpCamera();
    void start(TARGET*, FVector*, f32);
    void end();
    void update();
    CloseUpCamera(CloseUpCamera*, TARGET*, FVector*, f32);
};

}  // namespace worldmap

