#include "munny.hpp"

namespace Tz {

extern "C" u32 getSaveRam() asm("_Z10getSaveRamv");

u32 Munny::Get() {
    u32 p = getSaveRam();
    return *(u32*)((u32)p + 9280);
}

}  // namespace Tz
