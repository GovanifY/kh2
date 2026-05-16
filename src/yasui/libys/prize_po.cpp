#include "types.h"


namespace YS {

} // namespace YS

class FVector;
class OBJENTRY;
class PRIZE_PO;

class PRIZE_PO {
public:
 PRIZE_PO(PRIZE_PO* a0, OBJENTRY* a1);
 s32 Appear(FVector* a0, FVector* a1, s32 a2);
 s32 AppearForPO06(FVector* a0, s32 a1, s32 a2);
};
