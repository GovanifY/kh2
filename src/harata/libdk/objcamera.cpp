#include "objcamera.hpp"

namespace dk {

extern ObjCamera D_00348710 asm("D_00348710");
extern u32 D_00348750 asm("D_00348750");

ObjCamera* ObjCamera::getInstance() { return &D_00348710; }

s32 ObjCamera::getMode() { return (s32)D_00348750; }

void ObjCamera::initRadius() {
    ObjCameraLayout* c = reinterpret_cast<ObjCameraLayout*>(this);
    c->radius = c->defaultRadius;
}

void ObjCamera::initLockRadius() {
    ObjCameraLayout* c = reinterpret_cast<ObjCameraLayout*>(this);
    c->radius = c->defaultLockRadius;
}

}  // namespace dk
