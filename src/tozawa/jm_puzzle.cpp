#include "types.h"

namespace Tz {

extern volatile u8* volatile D_0035f638 asm("D_0035f638");
extern s8 D_00374cd0[] asm("D_00374cd0");
extern "C" void func_002fde18(void*, u32, u32);

class JmPuzzle {
public:
    static void InitInfo();
    static u32 CalcMaxPiece(s32);
};

void JmPuzzle::InitInfo() {
    u32 s0 = 0x00360000;
    (void)s0;
    func_002fde18((void*)D_0035f638, 0, 152);

    {
        volatile u8* p = D_0035f638;
        s32 m = -1;
        *(volatile s8*)(p + 52) = (s8)m;
    }

    {
        s32 m = -257;
        volatile u8* p = D_0035f638;
        u32 w = *(volatile u32*)(p + 52);
        w = w & (u32)m;
        *(volatile u32*)(p + 52) = w;
    }

    {
        s32 m = -513;
        volatile u8* p = D_0035f638;
        u32 w = *(volatile u32*)(p + 52);
        w = w & (u32)m;
        *(volatile u32*)(p + 52) = w;
    }

    {
        s32 m = -2049;
        volatile u8* p = D_0035f638;
        u32 w = *(volatile u32*)(p + 52);
        w = w & (u32)m;
        *(volatile u32*)(p + 52) = w;
    }
}

u32 JmPuzzle::CalcMaxPiece(s32 a0) {
    s8* p = (s8*)((u8*)&D_00374cd0 + (a0 << 2));
    return (s32)p[0] * (s32)p[1];
}

}  // namespace Tz
