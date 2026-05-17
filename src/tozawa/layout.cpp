#include "layout.hpp"

namespace Tz {

struct LayoutLayout {
    char _pad0[140];
    s32 num;
    s32 nextNum;
};

s32 Layout::getNum() { return reinterpret_cast<LayoutLayout*>(this)->num; }
s32 Layout::getNextNum() { return reinterpret_cast<LayoutLayout*>(this)->nextNum; }
}  // namespace Tz
