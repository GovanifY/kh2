#include "types.h"


namespace YS {

} // namespace YS

class BTLOBJ;
class OBJ_ATTACK;
class STDOBJ;

class OBJ_ATTACK {
public:
 OBJ_ATTACK(OBJ_ATTACK* a0, BTLOBJ* a1);
 void set_attack(s32 a0, s32 a1, STDOBJ* a2, s32 a3);
 void combo_start(void);
 void clear(void);
};
