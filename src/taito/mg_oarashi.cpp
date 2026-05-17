#include "mg_oarashi.hpp"

namespace Ti {


struct MGOarashiLayout {
    char _pad0[100];
    s32 configValue;
};

s32 MGOarashi::config() { return reinterpret_cast<MGOarashiLayout*>(this)->configValue; }
}  // namespace Ti
