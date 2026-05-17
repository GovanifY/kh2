#include "laymsg.hpp"

namespace Tz {
struct LayMsgLayout {
    char _pad0[28];
    s32 sequence;
};

s32 LayMsg::getSequence() { return reinterpret_cast<LayMsgLayout*>(this)->sequence; }
}  // namespace Tz
