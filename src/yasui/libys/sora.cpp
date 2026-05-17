#include "sora.hpp"

namespace YS {


extern "C" u32 func_001a8b28();
extern "C" u32 func_001a8bd0(s32);
extern "C" u32 func_001a8bf8(u32, u32);

u32 SORA::Get() {
    u32 b = (0x0035u << 16);
    return *(u32*)((u32)b + 9216);
}

u32 SORA::GetEntryId(s32 a0) {
    u32 s1 = func_001a8b28();
    u32 t = (u32)a0 << 1;
    u32 p = t + s1;
    if (a0 == 0) {
        u32 v = func_001a8bd0(-1);
        u32 idx = func_001a8bf8(v, 0);
        u32 q = (idx << 1) + s1;
        return *(u16*)(q + 16);
    }
    return *(u16*)(p + 22);
}

void SORA::set_skateboard_mode(s32 v) {
    reinterpret_cast<SORALayout*>(this)->skateboard_mode = v;
}
}  // namespace YS
