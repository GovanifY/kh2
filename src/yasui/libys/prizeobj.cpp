#include "types.h"


namespace YS {

} // namespace YS

class FVector;
class FuncDef63;
class OBJENTRY;
class PARAM;
class PRIZEOBJ;

class PRIZEOBJ {
public:
 void _OVR_exec(void);
 PRIZEOBJ(PRIZEOBJ* a0, OBJENTRY* a1, s32 a2, u32 a3);
 u64 appear(PARAM* a0, FVector* a1, FuncDef63* a2);
};
