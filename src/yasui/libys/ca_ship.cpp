#include "types.h"


namespace YS {

} // namespace YS

class AREA;
class JUMPER;

class CA_SHIP {
public:
 u64 IsSkipArea(AREA* a0, JUMPER* a1);
 void ArriveArea(AREA* a0);
 void ProgressCallback(s32 a0);
 u16 GetDisableReason(s32 a0, s32 a1);
 u64 IsDisableArea(s32 a0, s32 a1);
};
