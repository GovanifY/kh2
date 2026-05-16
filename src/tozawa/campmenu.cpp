#include "types.h"

namespace Tz {

class CampMenu {
public:
    static u32 StartJiminy(s32, s32);
    static void SetJmStartMenu(s32);
};

void CampMenu::SetJmStartMenu(s32 menu) {
    u32 b = (0x0036u << 16);
    *(u32*)((u32)b + (-4420)) = (u32)menu;
}

extern "C" u32 func_00253180(...);
extern "C" u32 func_00274f98(...);

u32 CampMenu::StartJiminy(s32 a0, s32 a1) {
    u32 r4 = (u32)a0, r5 = (u32)a1, r2, r15, r16;
    r15 = (u32)((s32)0u + (1));
    r16 = r4;
    r4 = r5;
    if (r16 != r15) {
        r2 = ((u32(*)(u32,u32))func_00274f98)(r4, r5);
    }
    r5 = r16;
    r4 = (u32)((s32)0u + (4));
    return ((u32(*)(u32,u32))func_00253180)(r4, r5);
}

}  // namespace Tz
