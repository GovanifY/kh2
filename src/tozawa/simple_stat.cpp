#include "types.h"

namespace Tz {

extern u32 D_0035f244 asm("D_0035f244");
extern s8 D_0035f24c asm("D_0035f24c");
extern u8 D_00374050 asm("D_00374050");

class SimpleStat {
public:
    static void FadeOut();
};

extern "C" u32 func_00139d78(...);
extern "C" u32 func_0028dac8(...);

void SimpleStat::FadeOut() {
    if (func_00139d78(D_0035f244) == 0) {
        return;
    }
    s32 i = (s32)D_0035f24c;
    u32 ptab = (u32)&D_00374050 + i * 6;
    s16 target = *(s16*)(ptab + 2);
    if (func_00139d78(D_0035f244) == 0) {
        return;
    }
    u32 p = D_0035f244;
    if (*(u32*)(p + 388) == (u32)(s32)target) {
        return;
    }
    func_0028dac8(p, (s32)target);
}

}  // namespace Tz
