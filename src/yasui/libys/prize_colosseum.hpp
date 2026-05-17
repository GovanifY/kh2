#ifndef KH2_SRC_YASUI_LIBYS_PRIZE_COLOSSEUM_HPP
#define KH2_SRC_YASUI_LIBYS_PRIZE_COLOSSEUM_HPP

#include "../../common/types.h"

class FVector;
class MASSEFFECT;
class OBJENTRY;
class PRIZETABLE;
class PRIZE_COLOSSEUM;

namespace YS {

    class PRIZE_COLOSSEUM {
    public:
     PRIZE_COLOSSEUM(PRIZE_COLOSSEUM* a0, OBJENTRY* a1);
     void AppearTable(FVector* a0, PRIZETABLE* a1);
     u64 PhaseColosseumMove(MASSEFFECT* a0);
    };

}  // namespace YS

#endif
