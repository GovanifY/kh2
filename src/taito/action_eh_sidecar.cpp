#include "types.h"


namespace Ti {

} // namespace Ti

class ACTION_EH_SIDECAR;
class OBJ;

class ACTION_EH_SIDECAR {
public:
 void start(OBJ* a0);
 void control(OBJ* a0);
 void calc_movement(OBJ* a0);
 ~ACTION_EH_SIDECAR();
};
