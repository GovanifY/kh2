#include "types.h"


namespace YS {

} // namespace YS

class ACTION_LM;
class OBJ;

class ACTION_LM {
public:
 u64 control(OBJ* a0);
 void calc_movement(OBJ* a0);
 ~ACTION_LM();
 ACTION_LM();
};
