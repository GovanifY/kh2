#include "laymsg.hpp"

namespace Tz {
s32 LayMsg::getSequence() { return reinterpret_cast<LayMsgLayout*>(this)->sequence; }
}  // namespace Tz
