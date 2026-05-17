#ifndef KH2_SRC_HARATA_LIBDK_GAUGE_STATUS_HPP
#define KH2_SRC_HARATA_LIBDK_GAUGE_STATUS_HPP

#include "../../common/types.h"

class OBJ;

namespace dk {

    class GAUGE_STATUS {
    public:
     double calcRate(s32 a0, s32 a1);
     u64 isAlert(OBJ* a0);
     u64 isDead(OBJ* a0);
     double calcHpRate(OBJ* a0);
     double calcMpRate(OBJ* a0);
    };

}  // namespace dk

#endif
