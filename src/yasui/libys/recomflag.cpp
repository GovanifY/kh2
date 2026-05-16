#include "types.h"

namespace YS {
class RECOM_FLAG {
public:
    void clear();
};

void RECOM_FLAG::clear() {
    u32 a0 = (u32)this;
    u32 t6 = (u32)((s32)a0 + 96);
    do {
        *(u32*)((u32)a0 + (s32)(0)) = 0u;
        a0 = (u32)((s32)a0 + (12));
    } while ((s32)a0 < (s32)t6);
}
}  // namespace YS
