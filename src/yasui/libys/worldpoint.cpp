#include "types.h"


namespace YS {

} // namespace YS

class WORLDPOINT {
public:
 void SysInit(void);
 void GetArea(s32 a0);
 s32 AreaToNum(s32 a0, s32 a1);
 void Visit(s32 a0);
 void Reset(s32 a0);
 u64 GetStatus(s32 a0);
 void GetDisableReason(s32 a0);
 void ProgressCallback(s32 a0);
};
