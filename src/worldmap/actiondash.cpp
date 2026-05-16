#include "types.h"


namespace worldmap {

} // namespace worldmap

class ActionDash;
class OBJ;

class ActionDash {
public:
 void start(OBJ* a0);
 void end(OBJ* a0);
 void control(OBJ* a0);
 void calc_movement(OBJ* a0);
 void party_jump(OBJ* a0, bool a1);
 ~ActionDash();
};
