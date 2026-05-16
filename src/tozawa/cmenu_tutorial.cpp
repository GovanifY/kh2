#include "types.h"

namespace Tz {

class CmTutorial {
public:
    static u32 LeaveAll();
};

extern "C" u32 func_0027d350(...);
extern "C" u32 func_00287bc0(...);

u32 CmTutorial::LeaveAll() {
    u32 r2 = func_00287bc0();
    if (r2 != 36u) {
        return r2;
    }
    return func_0027d350();
}

}  // namespace Tz
