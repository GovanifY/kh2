#pragma once

#include "../../common/types.h"

class ATTACK;
class ATTACKPARAM;
class ATTACK_WORK;
class BTLOBJ;
class COLLISION;
class DAMAGE;
class ENEMY;
class FVector;
class OBJ;
class OBJENTRY;
class STDOBJ;
class UNIT_DATA_OBJ;
class UNIT_GROUP;

namespace YS {

class ENEMY {
public:
 void _OVR_pre_exec(void);
 void _OVR__dead(void);
 void _OVR_exec_damage(DAMAGE* a0);
 ENEMY(ENEMY* a0, OBJENTRY* a1, FVector* a2, f32 a3);
 void Each(ENEMY* a0);
 void Init(void);
 u64 GetLastAttacker(void);
 void StopStartAll(s32 a0);
 void MakeSpace(COLLISION* a0);
};

class ENEMY> {
public:
 void initialize(OBJ* a0);
 void pre_exec(OBJ* a0);
 void exec(OBJ* a0);
 void post_exec(OBJ* a0);
 void _destroy(OBJ* a0);
 void leave_req(OBJ* a0);
 void check_leave(OBJ* a0);
 void leave(OBJ* a0);
 void fall(OBJ* a0);
 void land(OBJ* a0);
 void signal_callback(OBJ* a0, s32 a1, s32 a2);
 void set_unit_data(OBJ* a0, UNIT_GROUP* a1, UNIT_DATA_OBJ* a2);
 void get_data_priority(OBJ* a0);
 void is_control(OBJ* a0);
 void hide(OBJ* a0);
 void show(OBJ* a0);
 void attack_combo_start(STDOBJ* a0);
 void attack_on(STDOBJ* a0, s32 a1, s32 a2, STDOBJ* a3, s32 a4);
 void voice(STDOBJ* a0, s32 a1, s32 a2);
 void is_withstand(BTLOBJ* a0, DAMAGE* a1);
 void _dead(BTLOBJ* a0);
 void is_star(BTLOBJ* a0);
 void exec_damage(BTLOBJ* a0, DAMAGE* a1);
 void exec_damage_reaction(BTLOBJ* a0, DAMAGE* a1);
 void exec_reflect(BTLOBJ* a0, ATTACK_WORK* a1, ATTACK_WORK* a2);
 void exec_reflect_bg(BTLOBJ* a0, ATTACK* a1);
 void attack_callback(BTLOBJ* a0, BTLOBJ* a1, ATTACK* a2, ATTACKPARAM* a3);
 void add_hp(BTLOBJ* a0, s32 a1, s32 a2, bool a3);
};

} // namespace YS

