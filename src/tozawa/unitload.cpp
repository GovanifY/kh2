#include "types.h"

namespace Tz {

class UnitLoad {
public:
    static u32 isReading();
};

extern "C" u32 func_001688b8();

u32 UnitLoad::isReading() {
    u32 t5;
    if (func_001688b8() != 0) {
        goto set1;
    }
    t5 = 0;
    {
        u32 base = 0x00360000u;
        u32 t6 = *(u8*)(base + (s32)-2846);
        if (t6 == 0) {
            goto out;
        }
    }
set1:
    t5 = 1;
out:
    return t5;
}

}  // namespace Tz
