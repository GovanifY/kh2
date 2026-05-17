#include "jm_newinfo.hpp"

namespace Tz {

extern "C" u32 getSaveRam() asm("_Z10getSaveRamv");

extern "C" void func_00106420(u32);
extern "C" void func_002a9df0(...);
extern "C" void func_002aa220(...);
extern "C" void func_002aa4a8(...);
extern "C" void func_002aa960(...);
extern "C" void func_002aabe8(...);
extern "C" void func_002ab020(...);
extern "C" void func_002ab448(...);
extern "C" void func_002ab818(...);
extern "C" void func_002abba8(...);
extern "C" void func_002abe28(...);
extern "C" void func_002ac2e8(...);
extern u32 D_0035f610 asm("D_0035f610");

void JmNewInfo::Exit() {
    u32 r15 = D_0035f610;
    if (r15 != 0u) {
        func_00106420(r15);
        D_0035f610 = 0u;
    }
}

void JmNewInfo::CheckAll() {
    func_002a9df0();
    func_002aa220();
    func_002aa4a8();
    func_002aa960();
    func_002aabe8();
    func_002ab020();
    func_002ab448();
    func_002ab818();
    func_002abba8();
    func_002abe28();
    func_002ac2e8();
}

u32 JmNewInfo::GetSram() {
    u32 r2 = getSaveRam();
    r2 = (u32)((s32)r2 + 19512);
    return r2;
}

}  // namespace Tz
