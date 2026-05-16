#include "types.h"

namespace YS {

class PARTY {
public:
    u32 get_ability();
    u32 get_partram();
};

u32 PARTY::get_ability() {
    u32 v = *(u32*)((u32)this + 1164);
    return (u32)((s32)v + 460);
}

u32 PARTY::get_partram() {
    u32 p = *(u32*)((u32)this + 1164);
    return *(u32*)((u32)p + 580);
}

}  // namespace YS
