#include "types.h"


namespace Ti {

} // namespace Ti


class MGUnitSeq {
public:
 s32 find_unit(uint* a0, s32 a1, s32 a2, s32 a3, s32 a4);
 u64 find_loop_end(s32 a0, s32 a1);
 u64 find_return_end(s32 a0, s32 a1);
};
