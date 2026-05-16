#include "types.h"


namespace YS {

} // namespace YS

class CROWDEFFECT;
class FVector;
class MANAGER;
class MASSEFFECT;
class PARAM;

class CROWDEFFECT {
public:
 CROWDEFFECT(CROWDEFFECT* a0, MANAGER* a1, FVector* a2, PARAM* a3);
 void is_culling(void);
 void PreExec(void);
 u64 Exec(MASSEFFECT* a0);
};
