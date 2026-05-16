#include "types.h"

namespace Tz {

extern "C" u32 getSaveRam() asm("_Z10getSaveRamv");

class CmNewFlg {
public:
    static u32 GetSram();
};

u32 CmNewFlg::GetSram() {
    u32 r2 = getSaveRam();
    r2 = (u32)((s32)r2 + 16808);
    return r2;
}

}  // namespace Tz
