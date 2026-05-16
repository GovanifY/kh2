#include "types.h"


namespace YS {

} // namespace YS

class ACTION_CARPETBLOW;
class FVector;
class OBJ;

class ACTION_CARPETBLOW {
public:
 void start(OBJ* a0);
 void land(OBJ* a0);
 void calc_movement(OBJ* a0);
 void jump(OBJ* a0, FVector* a1);
 void jump_height(OBJ* a0, f32 a1);
 ~ACTION_CARPETBLOW();
 ACTION_CARPETBLOW();
};
