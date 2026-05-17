#include "friend_personality.hpp"

namespace kn {
class Friend;



struct FriendPersonalityLayout {
    char _pad0[4];
    Friend* obj;
};

f32 FriendPersonality::getBattleCancelDistance() const {
    u32 p = *(u32*)((u32)this + 8);
    return *(f32*)((u32)p + 128);
}

extern "C" u32 func_0010eed8(...);
extern "C" u32 func_001c0cd8(...);
extern "C" u32 func_001c0e60(...);

void FriendPersonality::start_limit() {
    u32 s0 = (u32)this;
    func_0010eed8(*(volatile u32*)((u32)this + (s32)(4)), 0u, 0u);
    u32 v0 = func_001c0cd8(*(volatile u32*)((u32)s0 + (s32)(4)));
    if (v0 != 0u) {
        func_001c0e60(*(volatile u32*)((u32)s0 + (s32)(4)));
    }
}

void FriendPersonality::setObj(Friend* v) {
    reinterpret_cast<FriendPersonalityLayout*>(this)->obj = v;
}
}  // namespace kn
