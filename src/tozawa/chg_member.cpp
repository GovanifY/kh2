#include "types.h"

namespace Tz {

extern u8 D_0035f4f9 asm("D_0035f4f9");
extern u32 D_0035f4f4 asm("D_0035f4f4");
extern u32 D_0035f2b0 asm("D_0035f2b0");

class ChgMember {
public:
    static u32 isLoadExec();
    static u32 isLoadFinish();
    static u32 Load();
    static void* GetMember();
};

u32 ChgMember::isLoadExec() {
    (void)D_0035f4f9;
    u32 b = (0x0036u << 16);
    return (u32)(*(u8*)((u32)b + (-2823)));
}

extern u8 D_0035f4f9 asm("D_0035f4f9");
extern "C" u32 func_00102a38(...);
extern "C" u32 func_00103eb0(...);
extern "C" u32 func_00170320(...);
extern "C" u32 func_00170cd0(...);
extern "C" u32 func_00290940(...);
extern "C" void func_00290a60(...);
extern u8 D_00293848 asm("D_00293848");

u32 ChgMember::isLoadFinish() {
    if (D_0035f4f9 == 0) {
        return 0;
    }
    if (func_00102a38(*(u32*)(func_00103eb0() + 4), (u32)&D_00293848) != 0) {
        return 0;
    }
    return (func_00170cd0() ^ 1) & 0xff;
}

u32 ChgMember::Load() {
    if (func_00290940(*(u32*)(u32)&D_0035f2b0) != 0u) {
        func_00290a60(*(u32*)(u32)&D_0035f2b0);
    }
    return func_00170320(5100u);
}

void* ChgMember::GetMember() { return reinterpret_cast<void*>(D_0035f4f4); }

}  // namespace Tz
