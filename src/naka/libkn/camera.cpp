#include "types.h"

namespace kn {
extern u32 D_0033cc44 asm("D_0033cc44");
extern u32 D_0033cc50 asm("D_0033cc50");

void setCameraMulti(bool value);
void setCameraNumber(s32 value);

class Camera {
public:
    ~Camera();
    f32 getRoll() const;
    void setRoll(f32);
    void setUpVector(f32, f32, f32);
    void setPosition(f32, f32, f32);
    void setReference(f32, f32, f32);
};

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

f32 Camera::getRoll() const { return reinterpret_cast<const CameraLayout*>(this)->roll; }
Camera::~Camera() { *(u32*)((u32)this + 0) = (u32)&D_0033cc50; }
void Camera::setRoll(f32 roll) { *(volatile f32*)((u32)this + (s32)(128)) = roll; }
void setCameraMulti(bool value) { *(u8*)&D_0033cc44 = (u8)((u32)value & 0xffu); }
void setCameraNumber(s32 value) {
    u32 b = (0x0034u << 16);
    *(u32*)((u32)b + (-13248)) = (u32)value;
}
void Camera::setUpVector(f32 x, f32 y, f32 z) {
    *(f32*)((u32)this + 112) = x;
    *(f32*)((u32)this + 116) = y;
    *(f32*)((u32)this + 120) = z;
}
void Camera::setPosition(f32 x, f32 y, f32 z) {
    CameraLayout* c = reinterpret_cast<CameraLayout*>(this);
    c->positionX = x;
    c->positionY = y;
    c->positionZ = z;
}
void Camera::setReference(f32 x, f32 y, f32 z) {
    CameraLayout* c = reinterpret_cast<CameraLayout*>(this);
    c->referenceX = x;
    c->referenceY = y;
    c->referenceZ = z;
}
}  // namespace kn
