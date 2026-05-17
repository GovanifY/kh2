#include "../tozawa/scroll_bar.hpp"

namespace Tz {

extern "C" u32 func_0028be58(...);

void ScrollBar::Leave() {
    u8* s0 = (u8*)this;
    if (func_0028be58(s0) != 0u) {
        void* obj = *(void**)s0;
        ((void (*)(void*))(*(u32*)(*(u32*)obj + 20u)))(obj);
    }
}

extern "C" u32 func_00257770();
extern "C" u32 func_00139d78(u32);
extern "C" void func_0028dac8(...);

void ScrollBar::FadeOut() {
    u32 s0 = func_00257770() + 2504;
    if (func_00139d78(s0) != 0) {
        func_0028dac8(s0, 243);
    }
}

}  // namespace Tz
