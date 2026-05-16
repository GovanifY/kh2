#include "types.h"


namespace dk {

} // namespace dk

class OBJ;

class GAUGE_STATUS {
public:
 double calcRate(s32 a0, s32 a1);
 u64 isAlert(OBJ* a0);
 u64 isDead(OBJ* a0);
 double calcHpRate(OBJ* a0);
 double calcMpRate(OBJ* a0);
};
