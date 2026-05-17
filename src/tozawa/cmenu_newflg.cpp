#include "cmenu_newflg.hpp"

namespace Tz {

extern "C" u32 getSaveRam() asm("_Z10getSaveRamv");

u32 CmNewFlg::GetSram() {
    u32 r2 = getSaveRam();
    r2 = (u32)((s32)r2 + 16808);
    return r2;
}

}  // namespace Tz
