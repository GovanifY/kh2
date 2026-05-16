#include "types.h"


namespace YS {

} // namespace YS

class ACTION_LIGHTCYCLE;
class OBJ;

class ACTION_LIGHTCYCLE {
public:
 void CheckCrash(OBJ* a0);
 void start(OBJ* a0);
 bool IsRun(OBJ* a0);
 void control(OBJ* a0);
 void calc_movement(OBJ* a0);
 ~ACTION_LIGHTCYCLE();
 ACTION_LIGHTCYCLE();
};
