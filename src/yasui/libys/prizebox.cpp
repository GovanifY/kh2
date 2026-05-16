#include "types.h"


namespace YS {

} // namespace YS

class BTLOBJ;
class FVector;
class OBJENTRY;
class PRIZEBOX;

class PRIZEBOX {
public:
 void get(BTLOBJ* a0);
 void _OVR_exec(void);
 PRIZEBOX(PRIZEBOX* a0, OBJENTRY* a1, FVector* a2, s32 a3, f32 a4);
 u64 Appear(s32 a0, FVector* a1);
 void ClearAll(void);
 void Read(void);
 void AladdinDrain(void);
 void DropNmPresent(BTLOBJ* a0, s32 a1);
};
