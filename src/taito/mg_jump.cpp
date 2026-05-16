#include "types.h"

namespace Ti {
class MGJump {
public:
    s32 config();
};

struct MGJumpLayout {
    char _pad0[112];
    s32 configValue;
};

s32 MGJump::config() { return reinterpret_cast<MGJumpLayout*>(this)->configValue; }
}  // namespace Ti
