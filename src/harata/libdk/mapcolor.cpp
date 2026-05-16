#include "types.h"

namespace dk {

extern u32 D_004f3694 asm("D_004f3694");

class MapColor {
public:
    static void* getFogDefault();
};

void* MapColor::getFogDefault() { return &D_004f3694; }

}  // namespace dk
