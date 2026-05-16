#include "types.h"

namespace dk {
class INFORMATION_WINDOW {
public:
    void close();
    s32 getMessage();
};

struct INFORMATION_WINDOW_Layout {
    char _pad0[456];
    s32 message;
};

s32 INFORMATION_WINDOW::getMessage() {
    return reinterpret_cast<INFORMATION_WINDOW_Layout*>(this)->message;
}

extern "C" void func_00138c10(u32, u32);
extern "C" void func_00139598(u32);

void INFORMATION_WINDOW::close() {
    u32 s0 = (u32)this;
    u32 s1 = (u32)this + 48;

    *(u32*)((u32)this + 972) = *(u32*)((u32)this + 972) | 1u;
    *(u32*)(s1 + 408) = 0u;

    func_00138c10(s1, 3u);

    *(s32*)(s1 + 392) = -1;
    func_00139598(s0 + 560);
}
}  // namespace dk
