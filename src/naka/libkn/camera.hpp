#ifndef KH2_SRC_NAKA_LIBKN_CAMERA_HPP
#define KH2_SRC_NAKA_LIBKN_CAMERA_HPP

#include "../../common/types.h"

namespace kn {

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

#endif
