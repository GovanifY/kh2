#ifndef KH2_SRC_YASUI_LIBYS_OBJATTACK_HPP
#define KH2_SRC_YASUI_LIBYS_OBJATTACK_HPP

#include "../../common/types.h"

class BTLOBJ;
class OBJ_ATTACK;
class STDOBJ;

namespace YS {

    class OBJ_ATTACK {
    public:
     OBJ_ATTACK(OBJ_ATTACK* a0, BTLOBJ* a1);
     void set_attack(s32 a0, s32 a1, STDOBJ* a2, s32 a3);
     void combo_start(void);
     void clear(void);
    };

}  // namespace YS

#endif
