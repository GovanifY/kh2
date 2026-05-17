#include "cmenu_help.hpp"

namespace Tz {

extern "C" u32 func_00263cc0();
extern u32 D_0035f0dc asm("D_0035f0dc");

void CMenuHelp::Leave() {
    if (func_00263cc0() == 0u) {
        return;
    }
    void* a0 = *(void**)(u32)&D_0035f0dc;
    u32 f = *(u32*)(*(u32*)a0 + 20u);
    ((void (*)(void*))f)(a0);
}

}  // namespace Tz
