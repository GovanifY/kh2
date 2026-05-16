#include "types.h"

extern u8 D_00345d40;

namespace kn {

class AbilityInfo {
public:
    static u32 ability2item(s32);
    static s32 item2index(s32);
};

u32 AbilityInfo::ability2item(s32 a0) {
    u32 t6 = 0;
    u8* v2 = &D_00345d40;
    while (1) {
        u32 t7 = *(u32*)(v2 + 0);
        if (t7 == (u32)a0) {
            return *(u32*)(v2 + 4);
        }
        t6 += 1;
        if ((s32)t6 < 29) {
            v2 += 16;
            continue;
        }
        return 0;
    }
}

s32 AbilityInfo::item2index(s32 a0) {
    u32 t6 = 0;
    u8* v2 = &D_00345d40;
    while (1) {
        u32 t7 = *(u32*)(v2 + 4);
        if (t7 == (u32)a0) {
            return *(s32*)(v2 + 12);
        }
        t6 += 1;
        if ((s32)t6 < 29) {
            v2 += 16;
            continue;
        }
        return -1;
    }
}

}  // namespace kn
