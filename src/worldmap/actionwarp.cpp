#include "types.h"


namespace worldmap {

} // namespace worldmap

class ActionWarp;
class OBJ;

class ActionWarp {
public:
 void start(OBJ* a0);
 void control(OBJ* a0);
 void calc_movement(OBJ* a0);
 ~ActionWarp();
};
