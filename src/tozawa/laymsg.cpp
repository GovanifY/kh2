#include "types.h"

namespace Tz {
class LayMsg {
public:
    s32 getSequence();
};

struct LayMsgLayout {
    char _pad0[28];
    s32 sequence;
};

s32 LayMsg::getSequence() { return reinterpret_cast<LayMsgLayout*>(this)->sequence; }
}  // namespace Tz
