#include "cameramanager.hpp"

namespace worldmap {
extern u8 D_01e2bda0 asm("D_01e2bda0");
extern "C" void func_002c6280(u32, u32);

void* CameraManager::get() {
    return &D_01e2bda0;
}

void CameraManager::removeAll() {
    s32 i = 0;
    while (1) {
        func_002c6280((u32)this, (u32)i);
        i += 1;
        if (i < 3) {
            continue;
        }
        break;
    }
}

}  // namespace worldmap
