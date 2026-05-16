#include "types.h"


namespace YS {

} // namespace YS

class ACTION_FLYJUMP;
class OBJ;

class ACTION_FLYJUMP {
public:
 void start(OBJ* a0);
 void control(OBJ* a0);
 void calc_movement(OBJ* a0);
 void land(OBJ* a0);
 ~ACTION_FLYJUMP();
 ACTION_FLYJUMP();
};
