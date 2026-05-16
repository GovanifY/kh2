#include "types.h"


namespace YS {

} // namespace YS

class ENEMYBASE;
class FVector;
class OBJENTRY;

class ENEMYBASE {
public:
 void _OVR_initialize(void);
 void _OVR_leave(void);
 void _OVR__dead(void);
 ENEMYBASE(ENEMYBASE* a0, OBJENTRY* a1, FVector* a2, f32 a3);
};
