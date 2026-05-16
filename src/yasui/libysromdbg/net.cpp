#include "types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace YS {

} // namespace YS

class ACCEPT_TABLE;

class NET {
public:
 void AddAcceptCallback(ACCEPT_TABLE* a0);
 void Lock(void);
 void Unlock(void);
};
