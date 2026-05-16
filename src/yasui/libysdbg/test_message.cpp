#include "types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace YS {

} // namespace YS

struct TASK;

class TEST_MESSAGE {
public:
 void Open(s32 a0);
 void ExecThread(TASK* a0);
 void Init(void);
};
