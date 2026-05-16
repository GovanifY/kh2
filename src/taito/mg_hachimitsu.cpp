#include "types.h"

namespace Ti {
class MGHachimitsu {
public:
    s32 get_gopher();
};

struct MGHachimitsuLayout {
    char _pad0[476];
    s32 gopher;
};

s32 MGHachimitsu::get_gopher() { return reinterpret_cast<MGHachimitsuLayout*>(this)->gopher; }
}  // namespace Ti
