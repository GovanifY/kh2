#include "types.h"

namespace dk {

class ScopeCamera {
public:
    static void destroy();
};

extern "C" u32 func_00140dc0(...);
extern "C" u32 func_00140dd0(...);
extern "C" u32 func_00140df0(...);

void ScopeCamera::destroy() {
    u32 s0 = func_00140df0();
    u32 v0 = func_00140dc0();
    if (v0 == 7u) {
        func_00140dd0(s0);
        return;
    }
}

}  // namespace dk
