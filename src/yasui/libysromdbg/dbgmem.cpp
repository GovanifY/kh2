#include "types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace YS {

} // namespace YS


class DBGMEM {
public:
 void Init(void);
 void Alloc(u32 a0);
 void Free(void* a0);
};
