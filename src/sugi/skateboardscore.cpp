#include "types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace Ts {

} // namespace Ts

struct TASK;

class SKATEBOARDSCORE {
public:
 void add_count(s32 a0, f32 a1);
 void stop(void);
 void ExecTask(TASK* a0);
 void ExecFinalize(TASK* a0);
};
