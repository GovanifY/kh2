#include "camera.hpp"

struct TASK;

namespace dk {

extern void storeImage() asm("_ZN2dk10storeImageEv");
extern s32 Camera_draw2Camera(void*) asm("_ZN2dk6Camera11draw2CameraEv");

void Camera::setNoKick() {
    u32 b = (0x0035u << 16);
    *(u8*)((u32)b + (-14478)) = (u8)0;
}

void Camera::after1CameraTask(TASK* task) {
    (void)task;
    storeImage();
}

void Camera::multiAfter2CameraTask(TASK* task) {
    (void)task;
    Camera_draw2Camera(this);
}

}  // namespace dk
