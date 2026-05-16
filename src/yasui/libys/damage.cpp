#include "types.h"

namespace YS {

class DAMAGE {
public:
    u32 is_count_combo() const;
};

u32 DAMAGE::is_count_combo() const {
    u32 v0 = 0u;
    u32 t7 = *(u32*)((u32)this + (s32)(24));
    t7 = (u32)(t7 & 0x4u);
    if (t7 != 0u) goto Lret;
    if (*(u8*)((u32)this + (s32)(38)) != (u8)5u) goto Lset;
    if (*(u32*)((u32)this + (s32)(40)) != 0u) goto Lset;
    goto Lret;
Lset:
    v0 = 1u;
Lret:
    return v0;
}

}  // namespace YS
