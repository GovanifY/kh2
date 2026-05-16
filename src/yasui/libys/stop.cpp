#include "types.h"

namespace YS {

class STOP {
public:
    u32 is_stop();
    u32 is_star();
};

u32 STOP::is_stop() {
    u32 v = *(u16*)((u32)this + 0);
    return v & 0x1u;
}

u32 STOP::is_star() {
    u32 v = *(u16*)((u32)this + 0);
    v >>= 2;
    return v & 0x1u;
}

}  // namespace YS
