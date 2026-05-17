#include "lockon.hpp"

namespace YS {


void LOCKON::auto_lock() {
    if (reinterpret_cast<LOCKONLayout*>(this)->mode != 1) {
        return;
    }
    u32 target = *(u32*)((u32)this + (s32)(40));
    u32 obj = *(u32*)((u32)target + (s32)(304));
    reinterpret_cast<LOCKONLayout*>(this)->lock_value = *(f32*)((u32)obj + (s32)(104));
}

void LOCKON::reset_player() { reinterpret_cast<LOCKONLayout*>(this)->player = 0; }
}  // namespace YS
