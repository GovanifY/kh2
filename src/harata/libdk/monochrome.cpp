#include "types.h"

namespace dk {

extern u32 D_00347ff8 asm("D_00347ff8");

class Monochrome {
public:
    static bool isMonochrome();
};

bool Monochrome::isMonochrome() { return D_00347ff8 == 1; }

}  // namespace dk
