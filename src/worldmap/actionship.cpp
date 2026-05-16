#include "types.h"


namespace worldmap {

} // namespace worldmap

class ActionShip;
class OBJ;

class ActionShip {
public:
 void control(OBJ* a0);
 void calc_movement(OBJ* a0);
 ~ActionShip();
};
