#include "../common/types.h"

namespace ryj {

class EFFECT {
public:
    u32 is_alive();
    void set_no_draw();
};

u32 EFFECT::is_alive() {
    u32 r2 = (u32)(s32)(*(s16*)((u32)this + (s32)(10)));
    r2 = (u32)(r2 ^ 0x0001u);
    r2 = (u32)(r2 & 0x0001u);
    return r2;
}

void EFFECT::set_no_draw() {
    u32 v = *(u32*)((u32)this + 8);
    v |= (u32)0x800000u;
    *(u32*)((u32)this + 8) = v;
}

}  // namespace ryj
