#include "types.h"

namespace Tz {

extern "C" u32 func_00139d78(...);

class LightCur {
public:
    void FadeOut();
    void Leave();
    u32 isExist();
};

u32 LightCur::isExist() {
    u32 (*fp_call0_00139d78)() = (u32(*)())func_00139d78;
    return fp_call0_00139d78();
}

void LightCur::FadeOut() {
    u8* s0 = (u8*)this;
    if (((LightCur*)s0)->isExist() != 0u) {
        s32 t6 = (s32)*(s16*)(s0 + 408);
        s32 t7 = *(s32*)(s0 + 388);
        if (t7 != t6) {
            u32 t6v = *(u32*)s0;
            ((void (*)(void*))(*(u32*)(t6v + 20u)))(s0);
        }
    }
}

void LightCur::Leave() {
    u8* s0 = (u8*)this;
    if (((LightCur*)s0)->isExist() != 0u) {
        u32 t7 = *(u32*)s0;
        ((void (*)(void*))(*(u32*)(t7 + 20u)))(s0);
    }
}

}  // namespace Tz
