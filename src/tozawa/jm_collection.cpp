#include "types.h"

namespace Tz {

extern u8 D_00360000 asm("D_00360000");
extern u8 D_00374928 asm("D_00374928");
extern "C" u32 func_0028b040(u32);
extern "C" u32 func_0029a5f0(u32);
extern "C" u32 func_00276c50(u32, u32);


class Select;

class JmCollection {
public:
    static void FileAlloc();
    static u32 DrawUpdate(Select*, s32, s32);
};

extern u32 D_0035f5a4 asm("D_0035f5a4");
extern u8 D_0035f5a8 asm("D_0035f5a8");
extern "C" u32 func_0023f900(u32);
extern "C" u32 func_00292630();
extern "C" u32 func_002953c8(u32);
extern "C" u32 func_00293db8(u32, u32);
extern "C" void func_0023fa08(u32, u32);

void JmCollection::FileAlloc() {
    func_0023f900(D_0035f5a4);
    if (func_00292630() == 0) {
        u8* p = (u8*)func_002953c8(15);
        u32 v = func_00293db8(2, (u32)(p + 1));
        func_0023fa08(D_0035f5a4, v);
        D_0035f5a8 = 1;
        return;
    }
    D_0035f5a8 = 0;
}

u32 JmCollection::DrawUpdate(Select*, s32, s32) {
    u32 v = func_0028b040(*(u32*)((u8*)&D_00360000 - 3584));
    v = func_0029a5f0(v);
    v <<= 1;
    v = (u32)((u8*)&D_00374928 + v);
    return func_00276c50(*(u16*)v, 0);
}

}  // namespace Tz
