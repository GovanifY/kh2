#include "timer.hpp"

extern u32 D_00349e00 asm("D_00349e00");

namespace dk {



u32 Timer::isDown() {
    u32 v = *(u8*)&D_00349e00;
    v ^= 0x1u;
    return (v < 1u);
}

}  // namespace dk
