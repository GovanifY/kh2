#include "mg_hachimitsu.hpp"

namespace Ti {


s32 MGHachimitsu::get_gopher() { return reinterpret_cast<MGHachimitsuLayout*>(this)->gopher; }
}  // namespace Ti
