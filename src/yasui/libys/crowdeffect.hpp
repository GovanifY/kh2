#pragma once

#include "../../common/types.h"

class CROWDEFFECT;
class FVector;
class MANAGER;
class MASSEFFECT;
class PARAM;

namespace YS {

    class CROWDEFFECT {
    public:
     CROWDEFFECT(CROWDEFFECT* a0, MANAGER* a1, FVector* a2, PARAM* a3);
     void is_culling(void);
     void PreExec(void);
     u64 Exec(MASSEFFECT* a0);
    };

}  // namespace YS

