#include "types.h"

namespace YS {

class ITEMPIC {
public:
    static u32 GetSequenceData();
};

u32 ITEMPIC::GetSequenceData() {
    u32 b = (0x01d5u << 16);
    return (u32)(*(u32*)((u32)b + (-29632)));
}

}  // namespace YS
