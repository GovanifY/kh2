#include "types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace YS {

} // namespace YS

class CODE;
class LIBRETTO;
struct TASK;

class TEST_LIBRETTO {
public:
 void Open(s32 a0);
 void ExecThread(TASK* a0);
 u64 Callback(CODE* a0, LIBRETTO* a1);
 void Init(void);
};
