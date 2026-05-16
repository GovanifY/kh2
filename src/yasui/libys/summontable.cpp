#include "types.h"


namespace YS {

} // namespace YS


class SUMMON_TABLE {
public:
 void read(void);
 void Init(void* a0);
 void MakeList(ushort* a0);
 s32 Get(s32 a0);
 s32 GetCurrent(void);
 s32 GetId(s32 a0);
 u64 Have(void);
};
