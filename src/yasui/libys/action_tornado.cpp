#include "types.h"


namespace YS {

} // namespace YS

class ACTION_TORNADO;
class BTLOBJ;
class OBJ;

class ACTION_TORNADO {
public:
 void SetDir(BTLOBJ* a0);
 void control(OBJ* a0);
 void CalcMovement(BTLOBJ* a0);
 ~ACTION_TORNADO();
 ACTION_TORNADO();
 void calc_movement(OBJ* a0);
};
