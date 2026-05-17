#pragma once

#include "../../common/types.h"

namespace kn {

struct CameraLayout {
    char _pad0[80];
    f32 positionX;
    f32 positionY;
    f32 positionZ;
    char _pad1[4];
    f32 referenceX;
    f32 referenceY;
    f32 referenceZ;
    char _pad2[20];
    f32 roll;
};

class Camera {
public:
    ~Camera();
    f32 getRoll() const;
    void setRoll(f32);
    void setUpVector(f32, f32, f32);
    void setPosition(f32, f32, f32);
    void setReference(f32, f32, f32);
};

void setCameraMulti(bool);
void setCameraNumber(s32);

}  // namespace kn
