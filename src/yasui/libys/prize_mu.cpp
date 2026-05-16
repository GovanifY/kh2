#include "types.h"


namespace YS {

} // namespace YS

class FVector;
class OBJENTRY;
class PRIZETABLE;
class PRIZE_MU;

class PRIZE_MU {
public:
 PRIZE_MU(PRIZE_MU* a0, OBJENTRY* a1);
 void AppearTable(FVector* a0, PRIZETABLE* a1);
 void AppearGauge(FVector* a0, f32 a1);
 void ClearAll(void);
};
