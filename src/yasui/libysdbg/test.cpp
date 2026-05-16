#include "types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace YS {

} // namespace YS

struct TASK;

class TEST {
public:
 void Init(void);
 void Test(s32 a0);
 void Thread(TASK* a0);
};
