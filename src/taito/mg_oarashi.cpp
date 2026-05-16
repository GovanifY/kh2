#include "types.h"

namespace Ti {
class MGOarashi {
public:
    s32 config();
};

struct MGOarashiLayout {
    char _pad0[100];
    s32 configValue;
};

s32 MGOarashi::config() { return reinterpret_cast<MGOarashiLayout*>(this)->configValue; }
}  // namespace Ti
