#include "types.h"

namespace YS {

class UNIT_GROUP {
public:
    static u32 Disable(s32);
    u32 get_rtn_param();
};

extern "C" u32 func_0019b260(u32);

u32 UNIT_GROUP::Disable(s32 group) {
    u32 r2 = func_0019b260((u32)group);
    u32 r15 = *(u32*)((u32)r2 + (s32)(4));
    r15 = (u32)(r15 | 0x0001u);
    *(u32*)((u32)r2 + (s32)(4)) = r15;
    return r2;
}

u32 UNIT_GROUP::get_rtn_param() {
    u32 r15 = *(volatile u32*)((u32)this + (s32)(8));
    u32 r14 = 6u;
    u32 r13 = (u32)(*(u8*)((u32)r15 + (s32)(0)));
    u32 r2 = 0u;
    if (r13 == r14) {
        r2 = *(volatile u32*)((u32)this + (s32)(48));
    }
    return r2;
}

}  // namespace YS
