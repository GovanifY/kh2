#include "types.h"

namespace SOUND {
u32 isSeAlertPlay();
void SE3DDisable();
void SE3DEnable();
void seVoicePcmStop();
}

extern "C" void func_002b72e4(s32, s32, u32);
extern "C" void func_002baa60(void);
extern "C" u32 func_002b83b4(void);
extern "C" u32 func_002b70b8(u32, u32, u32, u32);
extern u8 D_003616f0;

namespace SOUND {

u32 isSeAlertPlay() {
    u32 b = (0x0036u << 16);
    return (u32)(*(u8*)((u32)b + 5860));
}

void SE3DDisable() {
    *(u8*)&D_003616f0 = (u8)1u;
}

void SE3DEnable() {
    u32 b = (0x0036u << 16);
    *(u8*)((u32)b + 5872) = (u8)0u;
}

void seVoicePcmStop() {
    func_002b72e4(-100, -1, 0u);
    func_002baa60();
    func_002b83b4();
}

}  // namespace SOUND
