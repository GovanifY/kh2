#include "types.h"

namespace Tz {

extern "C" u32 getSaveRam() asm("_Z10getSaveRamv");

class Munny {
public:
    static u32 Get();
};

u32 Munny::Get() {
    u32 p = getSaveRam();
    return *(u32*)((u32)p + 9280);
}

}  // namespace Tz
