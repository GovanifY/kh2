#include "types.h"

namespace Tz {

extern u32 D_0035f520 asm("D_0035f520");

class JMData {
public:
    static u32 Clear(s32);
    static u32 Destroy(s32);
    static void LoadObjRequest(s32, bool);
    static u32 CacheAlloc(s32, const char*);
    static char* GetWorldStr(s32);
};

extern "C" u32 func_00292690(...) asm("_ZN2Tz8LoadData5ClearEi");
u32 JMData::Clear(s32 which) {
    u32 r15 = (u32)which;
    u32 r4 = 5100u;
    if (r15 != 0u) r4 = r15;
    return func_00292690(r4);
}

extern "C" u32 func_001703a8(u32);
u32 JMData::Destroy(s32 which) { return func_001703a8((u32)which); }

extern "C" u32 func_00292630(...);
extern "C" u32 func_0016e920(...);
extern "C" u32 func_0016f470(...);
extern "C" void func_00170a90(...);
extern "C" void func_0016ed50(...);
extern "C" void func_00293cb8(...);
extern "C" u32 func_002926a8(...);
extern u8 D_0035f4b8 asm("D_0035f4b8");

void JMData::LoadObjRequest(s32 a0, bool a1) {
    u32 flag = (u32)a1 & 0xff;
    func_00292630((u32)a0);
    if (flag != 0) {
        u32 v = func_0016e920((u32)a0 | 0x30000000);
        v = func_0016f470(v, 0);
        func_00170a90(v);
    }
    func_0016ed50((u32)a0 | 0x30000000, 5103, 30);
    D_0035f4b8 = 1;
}

u32 JMData::CacheAlloc(s32 a0, const char* a1) {
    u8 tmp[128];
    func_00293cb8(tmp, (u32)a0, (u32)a1);
    return func_002926a8(tmp);
}

char* JMData::GetWorldStr(s32 index) { return *(char**)((u32)&D_0035f520 + ((u32)index << 2)); }

}  // namespace Tz
