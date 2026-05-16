#include "types.h"

namespace Tz {

class SubMenu {
public:
    static u32 Exit(s32);
    static u32 GetCallSignal();
    static void SetLeadData(const char*);
};

extern "C" u32 func_002431c0(...);
extern "C" u32 func_00243150(...);
extern "C" u32 func_0028ca78(...);
extern "C" u32 func_0023fad0(...);
extern "C" u32 func_00287a28(...);
extern "C" u32 func_00242790(...);
extern "C" u32 func_0023d368(...);
extern "C" u32 func_002fee78(...);
extern "C" u32 func_0023fa90(...);
extern "C" u32 func_0023f900(...);
extern s32 D_0035ece0 asm("D_0035ece0");
extern u32 D_0033caf4 asm("D_0033caf4");
extern u8 D_00371830 asm("D_00371830");
extern u8 D_0035f3a8 asm("D_0035f3a8");

u32 SubMenu::GetCallSignal() {
    u32 r2 = func_002431c0();
    r2 = (u32)(r2 ^ 0x0016u);
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}

u32 SubMenu::Exit(s32) {
    D_0035ece0 = -1;
    u32 v0 = func_00243150();
    void (*fn)(void) = (void (*)(void))*(u32*)(v0 + 8);
    fn();
    func_0028ca78();
    func_0023fad0((void*)&D_0035f3a8);
    func_00287a28();
    func_00242790();
    return func_0023d368();
}

void SubMenu::SetLeadData(const char* a0) {
    u8 spbuf[128];
    ((void (*)(void*, const void*, u32, const char*))(u32)&func_002fee78)(spbuf, &D_00371830,
                                                                           D_0033caf4, a0);
    ((void (*)(void*, const void*))(u32)&func_0023fa90)(&D_0035f3a8, spbuf);
    ((void (*)(void*))(u32)&func_0023f900)(&D_0035f3a8);
}

}  // namespace Tz
