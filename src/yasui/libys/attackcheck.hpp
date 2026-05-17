#ifndef KH2_SRC_YASUI_LIBYS_ATTACKCHECK_HPP
#define KH2_SRC_YASUI_LIBYS_ATTACKCHECK_HPP

#include "../../common/types.h"

class ATTACK;
class ATTACKPARAM;
class ATTACK_CHECK;
class BTLOBJ;

namespace YS {

    class ATTACK_CHECK {
    public:
     void exec(void);
     void hit_interval_attack(ATTACK* a0, ATTACKPARAM* a1);
     ATTACK_CHECK(ATTACK_CHECK* a0, BTLOBJ* a1);
     ~ATTACK_CHECK();
     bool is_strike(ATTACK* a0);
     u64 is_hit(ATTACK* a0);
     s32 hit(ATTACK* a0, bool* a1);
     void unhit(ATTACK* a0);
     void Init(void);
     s32 NewAttackId(void);
     void FreeAttackId(s32 a0);
     s32 NewComboGroup(void);
     void Exec(void);
    };

}  // namespace YS

#endif
