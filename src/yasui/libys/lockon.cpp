#include "lockon.hpp"

namespace YS {


struct LOCKONLayout {
    s32 mode;
    char _pad_mode[24];
    f32 lock_value;
    char _pad0[8];
    s32 player;
};

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
