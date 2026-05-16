#include "types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace YS {

} // namespace YS

class AREA;
struct TASK;

class CHECK_CACHEBUFF {
public:
 void Init(void);
 u64 IsExec(void);
 void Start(s32 a0);
 void CheckAllSet(TASK* a0, AREA* a1);
 void CheckAllAreaThread(TASK* a0);
 void CheckAllSetThread(TASK* a0);
 void CheckThreadFinalizer(TASK* a0);
 void CheckProgress(TASK* a0);
 void RepeatThread(TASK* a0);
};
