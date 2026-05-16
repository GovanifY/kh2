#include "types.h"


namespace YS {

} // namespace YS

class ACTION_NMGUN;
class OBJ;

class ACTION_NMGUN {
public:
 void control(OBJ* a0);
 ~ACTION_NMGUN();
 ACTION_NMGUN();
 void calc_movement(OBJ* a0);
};
