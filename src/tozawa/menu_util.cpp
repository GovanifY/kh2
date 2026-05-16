#include "types.h"

namespace Tz {

class MenuUtil {
public:
    static u32 GetFontType(s32);
};

u32 MenuUtil::GetFontType(s32 a0) {
    s32 t6 = 100;
    s32 t7 = 10;
    s32 v0 = a0 % t6;
    s32 t6h = v0 % t7;
    v0 = v0 - t6h;
    v0 = v0 ^ 10;
    return (u32)(v0 == 0);
}

}  // namespace Tz
