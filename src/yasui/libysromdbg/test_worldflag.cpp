#include "types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace YS {

} // namespace YS

class TEST_WORLDFLAG;

class TEST_WORLDFLAG {
public:
 void set_flag(s32 a0);
 void check_flag(s32 a0);
 void Apply(void* a0);
 void Reset(void* a0);
 void Open(s32 a0);
 void Init(void);
 ~TEST_WORLDFLAG();
};
