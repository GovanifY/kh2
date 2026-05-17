#include "layout.hpp"

namespace Tz {

s32 Layout::getNum() { return reinterpret_cast<LayoutLayout*>(this)->num; }
s32 Layout::getNextNum() { return reinterpret_cast<LayoutLayout*>(this)->nextNum; }
}  // namespace Tz
