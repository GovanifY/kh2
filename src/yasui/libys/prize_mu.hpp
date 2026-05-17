#ifndef KH2_SRC_YASUI_LIBYS_PRIZE_MU_HPP
#define KH2_SRC_YASUI_LIBYS_PRIZE_MU_HPP

#include "../../common/types.h"

class FVector;
class OBJENTRY;
class PRIZETABLE;
class PRIZE_MU;

namespace YS {

    class PRIZE_MU {
    public:
     PRIZE_MU(PRIZE_MU* a0, OBJENTRY* a1);
     void AppearTable(FVector* a0, PRIZETABLE* a1);
     void AppearGauge(FVector* a0, f32 a1);
     void ClearAll(void);
    };

}  // namespace YS

#endif
