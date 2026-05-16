#include "types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace YS {

} // namespace YS

class OBJ;
struct TASK;

class TEST_CAMERA {
public:
 void ExecTask(TASK* a0);
 void Start(OBJ* a0);
 void Stop(void);
};
