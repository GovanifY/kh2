#include "mg_oarashi.hpp"

namespace Ti {


s32 MGOarashi::config() { return reinterpret_cast<MGOarashiLayout*>(this)->configValue; }
}  // namespace Ti
