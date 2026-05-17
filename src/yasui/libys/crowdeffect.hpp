#ifndef KH2_SRC_YASUI_LIBYS_CROWDEFFECT_HPP
#define KH2_SRC_YASUI_LIBYS_CROWDEFFECT_HPP

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

#endif
