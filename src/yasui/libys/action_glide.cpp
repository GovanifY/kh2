#include "types.h"


namespace YS {

} // namespace YS

class ACTION_GLIDE;
class OBJ;

class ACTION_GLIDE {
public:
 void start(OBJ* a0);
 void end(OBJ* a0);
 void control(OBJ* a0);
 void calc_movement(OBJ* a0);
 ~ACTION_GLIDE();
 ACTION_GLIDE();
};
