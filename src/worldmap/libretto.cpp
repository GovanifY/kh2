#include "libretto.hpp"

extern "C" void func_00170dd0(...);
extern "C" void func_002be0b0(...);
extern void* YS_CACHE_BUFF_Alloc(char const*, s32) asm("_ZN2YS10CACHE_BUFF5AllocEPKci");

namespace worldmap {

extern u32 D_003617fc asm("D_003617fc");



bool Libretto::isExec() { return D_003617fc != 0; }

void Libretto::leaveAllObj() {
    s32 i = 0;
    do {
        func_002be0b0(this, (u32)i);
        i += 1;
    } while (i < 4);
}

void Libretto::waitFlush() {
    u8* s0 = (u8*)this;
    u32 t7 = *(u32*)(s0 + 4);
    func_00170dd0(*(u32*)(t7 + 16));
    s8 t = *(s8*)(s0 + 64);
    if (t != 0) {
        u32 v = (u32)YS_CACHE_BUFF_Alloc((char const*)(s0 + 64), -1);
        *(u32*)(s0 + 104) = v;
    }
}

u32 Libretto::isExistObj() {
    s32 i = 0;
    u32* p = (u32*)(D_003617fc + 44);
    while (true) {
        if (*p != 0) {
            return 1;
        }
        p += 1;
        i += 1;
        if (i < 4) {
            continue;
        }
        return 0;
    }
}

}  // namespace worldmap
