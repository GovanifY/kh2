#include "types.h"

namespace YS {
class JUMPER {
public:
    void clear();
    u32 is_jump();
};

void JUMPER::clear() {
    char* p = reinterpret_cast<char*>(this);
    *(u32*)(p + 0) = 0;
    *(u32*)(p + 20) = (u32)-1;
    *(u32*)(p + 24) = 0;
    *(u32*)(p + 28) = 0;
    *(u32*)(p + 32) = 0;
}
u32 JUMPER::is_jump() { return (*(u32*)((u32)this + 0) != 0); }
}  // namespace YS
