#include "types.h"

namespace YS {

extern u32 D_01d48dc0 asm("D_01d48dc0");

class WORLDWORK {
public:
    static void* Get();
};

void* WORLDWORK::Get() { return &D_01d48dc0; }

}  // namespace YS
