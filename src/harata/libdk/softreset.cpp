#include "types.h"

namespace dk {

extern u32 D_0034926b asm("D_0034926b");

class SoftReset {
public:
    static void disable();
};

void SoftReset::disable() {
    u32 v = (u32)((s32)1);
    *(u8*)&D_0034926b = (u8)v;
}

}  // namespace dk
