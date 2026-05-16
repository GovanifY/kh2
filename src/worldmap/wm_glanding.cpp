#include "types.h"

namespace dk {

class WM_GLANDING {
public:
    u32 get_jump_flag();
};

u32 WM_GLANDING::get_jump_flag() {
    u32 v = *(u32*)((u32)this + 24);
    return v & 0x1u;
}

}  // namespace dk
