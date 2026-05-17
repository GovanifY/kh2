#include "map.hpp"

namespace dk {

extern u32 D_0034c6f0 asm("D_0034c6f0");
extern u8 D_0034c70c asm("D_0034c70c");



u32 Map::isPaxExist() {
    (void)D_0034c70c;
    u32 b = (0x0035u << 16);
    return (u32)(*(u8*)((u32)b + (-14580)));
}

void* Map::getPax() { return &D_0034c6f0; }

}  // namespace dk
