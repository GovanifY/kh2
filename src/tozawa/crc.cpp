#include "types.h"


namespace Tz {

} // namespace Tz

class ALLOCATOR;

class Crc {
public:
 void MakeTable(void);
 void CalcInit(void);
 void Init(ALLOCATOR* a0);
 void End(void);
 u32 Calc(uchar* a0, s32 a1);
};
