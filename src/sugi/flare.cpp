#include "types.h"

namespace Ts {

class FLARE {
public:
    static u32 IsEmpty();
};

u32 FLARE::IsEmpty() {
    u32 r15 = (0x01e3u << 16);
    u32 r14 = *(u32*)((u32)r15 + (s32)(-16480));
    u32 r2 = *(u32*)((u32)r14 + (s32)(2040));
    r2 = (u32)(r2 ^ 0x001eu);
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}

}  // namespace Ts
