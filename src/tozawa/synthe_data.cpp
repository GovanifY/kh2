#include "synthe_data.hpp"

namespace Tz {

extern "C" u32 func_00103570();
extern "C" void* func_001063c0(u32, u32);
extern "C" void func_0028b788(void*);
extern "C" u32 func_002537c8(u32);
extern "C" void func_0023fa08(void*, u32);
extern "C" void func_0028b8e0(void*, u32);
extern "C" void func_00290940(void*);
extern "C" void func_00253b30(u32, u32);
extern "C" void func_00290a10(u32, u32, u32);
extern "C" u32 func_00290a60(u32, u32, u32, u32);
extern void* D_0035f674 asm("D_0035f674");
extern u8 D_0035f3a8 asm("D_0035f3a8");
extern void* D_0035f6dc asm("D_0035f6dc");
extern u8* D_0035f6d8 asm("D_0035f6d8");

void SyntheData::LeadData(MenuFile* a0) {
    u8 buf[256];

    void* s0 = a0;
    if (s0 == 0) {
        s0 = D_0035f6dc;
    }

    func_00290940(s0);
    func_00253b30((u32)buf, (u32)D_0035f6d8);
    func_00290a10((u32)s0, (u32)buf, 45);
}

u32 SyntheData::GetMixDataFname() {
    u32 b = (0x0036u << 16);
    return *(u32*)((u32)b + (-2344));
}

}  // namespace Tz
