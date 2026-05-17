#pragma once

#include "../../common/types.h"

class ATTACK;
class ATTACKPARAM;
class ATTACK_WORK;
class BTLOBJ;
class DAMAGE;
class ENEMYPARAM;
class FVector;
class OBJ;
class OBJENTRY;
class PIERROT;

namespace YS {

    class PIERROT {
    public:
     void AddExp(ENEMYPARAM* a0, OBJ* a1, FVector* a2);
     void _OVR__dead(void);
     void set_attacker(OBJ* a0);
     void damage_se(DAMAGE* a0);
     void _OVR_exec_damage(DAMAGE* a0);
     void _OVR_exec_reflect(ATTACK_WORK* a0, ATTACK_WORK* a1);
     void _OVR_attack_callback(BTLOBJ* a0, ATTACK* a1, ATTACKPARAM* a2);
     PIERROT(PIERROT* a0, OBJENTRY* a1, u32 a2, FVector* a3, f32 a4);
     void set_sheet(s32 a0);
     void dup_sheet(s32 a0);
    };

}  // namespace YS

