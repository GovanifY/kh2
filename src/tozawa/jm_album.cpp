#include "types.h"

namespace Tz {

extern u32 D_0035f598 asm("D_0035f598");
extern s8 D_0035f5a1 asm("D_0035f5a1");
extern u8 D_0035f5a3 asm("D_0035f5a3");
extern "C" u32 func_002983d8(u32);
extern "C" u32 func_00292630();
extern "C" u32 func_00293de8(u32);
extern "C" void func_002ff2e8(void*, u32);
extern "C" void func_002feee8(u32, u32);
extern "C" void func_00298f90();
extern "C" void func_00293bd0(u32, void*, u32);
extern "C" void func_002925c0();

class JmAlbum {
public:
    static void RequestGraLoad(s32);
};

void JmAlbum::RequestGraLoad(s32 a0) {
    u8 buf[32];
    s32 idx = (s8)a0;
    u32 off = (u32)idx;
    off <<= 1;
    off += D_0035f598;
    D_0035f5a1 = (s8)a0;
    u32 s0 = (u32)func_002983d8(*(s16*)(off + 4));
    if (func_00292630() != 0) {
        D_0035f5a3 = 0;
        return;
    }
    u32 v = func_00293de8(*(s8*)s0);
    func_002ff2e8(buf, v);
    func_002feee8((u32)buf, s0 + 1);
    func_00298f90();
    func_00293bd0(3, buf, 0);
    func_002925c0();
    D_0035f5a3 = 1;
}

}  // namespace Tz
