#include "types.h"

namespace Tz {

extern u8 D_0035ef58 asm("D_0035ef58");
extern u8 D_0035eee0 asm("D_0035eee0");
extern u32 D_0035ef50 asm("D_0035ef50");
extern u32 D_0035ef54 asm("D_0035ef54");
extern "C" u32 func_001688b8(...);
extern "C" void func_002fde18(...);

class CMData {
public:
    static void Exit();
    static u32 isBackRead();
};

void CMData::Exit() {
    func_002fde18((void*)&D_0035eee0, 0, 112);
    D_0035ef50 = 0;
    D_0035ef54 = 0;
    if (D_0035ef58 != 0) {
        if (func_001688b8() == 0) {
            D_0035ef58 = 0;
        }
    }
}

u32 CMData::isBackRead() {
    (void)D_0035ef58;
    u32 b = (0x0036u << 16);
    return (u32)(*(u8*)((u32)b + (-4264)));
}

}  // namespace Tz
