#include "types.h"


namespace YS {

} // namespace YS

class FVector;
class MASSEFFECT;
class OBJENTRY;
class PRIZETABLE;
class PRIZE_COLOSSEUM;

class PRIZE_COLOSSEUM {
public:
 PRIZE_COLOSSEUM(PRIZE_COLOSSEUM* a0, OBJENTRY* a1);
 void AppearTable(FVector* a0, PRIZETABLE* a1);
 u64 PhaseColosseumMove(MASSEFFECT* a0);
};
