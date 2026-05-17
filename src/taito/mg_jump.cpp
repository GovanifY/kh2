#include "mg_jump.hpp"

namespace Ti {


s32 MGJump::config() { return reinterpret_cast<MGJumpLayout*>(this)->configValue; }
}  // namespace Ti
