#ifndef KH2_SRC_YASUI_LIBYS_CROWD_M_EX660_HPP
#define KH2_SRC_YASUI_LIBYS_CROWD_M_EX660_HPP

#include "../../common/types.h"

class CROWDEFFECT;

namespace YS {

    class CROWD_M_EX660 {
    public:
     void _OVR_exec(void);
     void ActionIdle(CROWDEFFECT* a0);
     void ActionDead(CROWDEFFECT* a0);
    };

}  // namespace YS

#endif
