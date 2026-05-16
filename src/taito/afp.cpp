#include "types.h"

namespace Ti {
class Afp {
public:
    s32 getCount(void* p);
};

struct AfpLayout {
    char _pad0[12];
    s32 count;
};

s32 Afp::getCount(void* p) {
    (void)p;
    return reinterpret_cast<AfpLayout*>(this)->count;
}
}  // namespace Ti
