#include "types.h"


namespace YS {

} // namespace YS

class FVector;
class OBJENTRY;
class PARTY;
class TREASURE_BOX;

class TREASURE_BOX {
public:
 void _OVR_initialize(void);
 TREASURE_BOX(TREASURE_BOX* a0, OBJENTRY* a1, FVector* a2, f32 a3);
 void open(PARTY* a0);
};
