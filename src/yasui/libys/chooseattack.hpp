#ifndef KH2_SRC_YASUI_LIBYS_CHOOSEATTACK_HPP
#define KH2_SRC_YASUI_LIBYS_CHOOSEATTACK_HPP

#include "../../common/types.h"

class CHOOSE_ATTACK;
class COLLISION;
class PARTY;
class TARGET;

namespace YS {

    class CHOOSE_ATTACK {
    public:
     void check_collision(COLLISION* a0, s32 a1);
     void check_enemy(void);
     CHOOSE_ATTACK(CHOOSE_ATTACK* a0, PARTY* a1, TARGET* a2);
     void get_attack(void);
    };

}  // namespace YS

#endif
