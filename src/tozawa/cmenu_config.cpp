#include "types.h"

namespace Tz {

class Select;

extern s8* D_0035f234 asm("D_0035f234");
extern u32 D_0035f254 asm("D_0035f254");

class CmConfig {
public:
    static void DrawUpdate(Select*, s32, s32);
    static u32 GetSelSeq(s32, s32);
};

extern "C" u32 func_00257770(...);
extern "C" u32 func_0028af88(...);
extern "C" u32 func_0028b040(...);
extern "C" void func_0028af18(...);
extern u8 D_00374168 asm("D_00374168");

void CmConfig::DrawUpdate(Select*, s32, s32) {
    u32 s1 = func_0028af88(D_0035f254);
    u32 i = func_0028b040(D_0035f254);
    s8 v = *((s8*)&D_00374168 + i);
    s32 m = -13;
    if (v >= 0) {
        goto clear_bits;
    }
    if (i == 2) {
        goto clear_bits;
    }
    s1 |= 0xcu;
    goto apply;
clear_bits:
    s1 &= (u32)m;
apply:
    func_0028af18(D_0035f254, s1);
}

u32 CmConfig::GetSelSeq(s32 a0, s32 a1) {
    u32 s0 = (u32)a1;
    u32 s1 = (u32)a0;
    u32 base = func_00257770();
    u32 t = s1 + s0;
    s1 <<= 2;
    if (t != 9) {
        s1 = (u32)((s32)s1 + (s32)D_0035f234[t]);
    }
    return base + (s1 * 436) + 13840;
}

}  // namespace Tz
