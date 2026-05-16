#include "types.h"

namespace Tz {

extern "C" u32 func_00276638(u32);
extern "C" u32 func_0029da68(u32);
extern "C" void func_00292b40(void*, u32);
extern "C" u32 func_002766d0();
extern u32 D_0035f5ac asm("D_0035f5ac");
extern "C" u32 func_00139d78(u32);
extern "C" u32 func_0028dac8(u32, u32);
extern "C" void func_0028d8c0(u32, u32, u32, u32, u32, u32, u32, u32);
extern "C" void func_0028dcc0(u32, u32);
extern u32 D_0035f14c asm("D_0035f14c");
extern u32 D_0035f148 asm("D_0035f148");
extern u32 D_0035f210 asm("D_0035f210");

class JmDic {
public:
    static void RequestGraLoad();
    static void SetupCharaInfo();
};

void JmDic::RequestGraLoad() {
    s16 tmp;
    u32 v0 = func_00276638(15);
    u32 base = 0x00360000u;
    v0 = v0 << 1;
    v0 = v0 + *(u32*)(base + (s32)-2644);
    v0 = func_0029da68((u32)(s16)*(u16*)(v0 + 8));
    tmp = *(s8*)(v0 + 1);
    func_00292b40(&tmp, 1);
}

void JmDic::SetupCharaInfo() {
    u32 s1 = func_002766d0();
    u32 s0 = s1 + 0x4860;

    if (func_00139d78(s0) != 0) {
        return;
    }

    func_0028d8c0(s0, 30055, D_0035f14c, D_0035f148, D_0035f210, 4, 5, 0);
    func_0028dcc0(s0, s1);
}

}  // namespace Tz
