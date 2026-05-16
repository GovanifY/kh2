#include "types.h"

namespace YS {

class SUMMON {
public:
    static void LeaveTink();
};

void SUMMON::LeaveTink() {
    u32 b = (0x0033u << 16);
    *(u8*)((u32)b + (-4009)) = (u8)0;
}

}  // namespace YS
