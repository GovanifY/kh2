#include "types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace Ts {

} // namespace Ts

class ACTION_SKATEBOARD;
class FVector;
class OBJ;

class ACTION_SKATEBOARD {
public:
 void start(OBJ* a0);
 void end(OBJ* a0);
 void jump(OBJ* a0, FVector* a1);
 void jump_height(OBJ* a0, f32 a1);
 void fall(OBJ* a0);
 void control(OBJ* a0);
 void calc_movement(OBJ* a0);
 void party_jump(OBJ* a0, bool a1);
 void Ride(OBJ* a0, OBJ* a1);
 void Trick(OBJ* a0, s32 a1, f32 a2);
 void TrickMotionPush(OBJ* a0, s32 a1, f32 a2);
 ~ACTION_SKATEBOARD();
};
