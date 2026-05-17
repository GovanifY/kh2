#include "mg_jump.hpp"

namespace Ti {


struct MGJumpLayout {
    char _pad0[112];
    s32 configValue;
};

s32 MGJump::config() { return reinterpret_cast<MGJumpLayout*>(this)->configValue; }
}  // namespace Ti
