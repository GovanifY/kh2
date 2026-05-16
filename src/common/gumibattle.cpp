#include "types.h"

namespace GUMIBATTLE {

u32 GetPauseParam() {
    u32 b = (0x0033u << 16);
    return (u32)(*(u32*)((u32)b + (-17800)));
}

}  // namespace GUMIBATTLE
