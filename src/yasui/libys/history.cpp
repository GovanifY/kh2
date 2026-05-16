#include "types.h"


namespace YS {

} // namespace YS

class HISTORY {
public:
 void init(void);
 void next(s32 a0);
 void set(s32 a0);
 void unset(s32 a0);
 u64 is_set(s32 a0);
 void clear(void);
 void Clear(void);
 void Init(void);
};

namespace YS {
void HISTORY_set_raw(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS7HISTORY3setEi");
void HISTORY_set_raw(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)(a0 + 8) = a1;
}
}  // namespace YS
