#ifndef KH2_SRC_TAITO_MG_OARASHI_GIMOBJ_HPP
#define KH2_SRC_TAITO_MG_OARASHI_GIMOBJ_HPP

#include "../common/types.h"

class DAMAGE;
class FVector;
class MGOarashiGimObj;
class OBJ;
class OBJENTRY;
class RotPrizeParam;

namespace Ti {

    class MGOarashiGimObj {
    public:
     void _OVR_initialize(void);
     void get_appear_przie_pos(void);
     double appear_fall_prize(void);
     void _OVR_exec(void);
     double appear_rot_prize(RotPrizeParam* a0, s32 a1);
     void reserve_fall_prize(s32 a0);
     void exec_damage_self(DAMAGE* a0);
     void _OVR_exec_damage(DAMAGE* a0);
     MGOarashiGimObj(MGOarashiGimObj* a0, OBJENTRY* a1, u32 a2, FVector* a3, f32 a4);
     void start_tornado_attack(void);
     void force_destroy(void);
     void vacuum_movement(OBJ* a0);
    };

}  // namespace Ti

#endif
