#include "types.h"


namespace YS {

} // namespace YS

class ACTION_AIRSLIDE;
class OBJ;

class ACTION_AIRSLIDE {
public:
 void control(OBJ* a0);
 void calc_movement(OBJ* a0);
 ~ACTION_AIRSLIDE();
 ACTION_AIRSLIDE();
};
