#include "types.h"

namespace Tz {

extern u32 D_0035ecd8 asm("D_0035ecd8");

class Config {
public:
    static u32 isEventViewer();
    static u32 isChapterAll();
    static u32 isVibration();
    static u32 isNaviOn();
    static u32 isCameraAuto();
    static u32 isCommandKH2();
    static u32 isRightStickCamera();
};

u32 Config::isEventViewer() {
    u32 v = D_0035ecd8;
    v = (u32)((s32)v >> 1);
    return v & 0x1u;
}

u32 Config::isChapterAll() {
    u32 v = D_0035ecd8;
    v = (u32)((s32)v >> 2);
    return v & 0x1u;
}

extern "C" u32 getSaveRam() asm("_Z10getSaveRamv");

u32 Config::isVibration() {
    u32 r2 = getSaveRam();
    r2 = *(u32*)((u32)r2 + 16804);
    r2 = (u32)(r2 & 0x0001u);
    return r2;
}

u32 Config::isNaviOn() {
    u32 r2 = getSaveRam();
    r2 = *(u32*)((u32)r2 + 16804);
    r2 = (u32)((s32)r2 >> 3);
    r2 = (u32)(r2 & 0x0001u);
    return r2;
}

u32 Config::isCameraAuto() {
    u32 r2 = getSaveRam();
    r2 = *(u32*)((u32)r2 + 16804);
    r2 = (u32)((s32)r2 >> 4);
    r2 = (u32)(r2 ^ 0x0001u);
    r2 = (u32)(r2 & 0x0001u);
    return r2;
}

u32 Config::isRightStickCamera() {
    u32 r2 = getSaveRam();
    r2 = *(u32*)((u32)r2 + 16804);
    r2 = (u32)((s32)r2 >> 5);
    r2 = (u32)(r2 ^ 0x0001u);
    r2 = (u32)(r2 & 0x0001u);
    return r2;
}

u32 Config::isCommandKH2() {
    u32 r2 = getSaveRam();
    r2 = *(u32*)((u32)r2 + 16804);
    r2 = (u32)((s32)r2 >> 6);
    r2 = (u32)(r2 ^ 0x0001u);
    r2 = (u32)(r2 & 0x0001u);
    return r2;
}

}  // namespace Tz
