#include "types.h"


namespace YS {

} // namespace YS

class ATTACK;
class BTLOBJ;
class DAMAGE;
class FVector;
class OBJ;
class OBJENTRY;
class PAX;
class STDOBJ;
class TARGET;
class UNIT_DATA_OBJ;
class UNIT_GROUP;

class BTLOBJ {
public:
 void _OVR_pre_exec(void);
 void _OVR__destroy(void);
 void _OVR_leave_req(void);
 void _exec_damage_small_air(DAMAGE* a0, f32 a1, s32 a2);
 u64 is_upper_damage(DAMAGE* a0);
 void exec_damage_small_spot(DAMAGE* a0);
 void set_hitback(FVector* a0, f32 a1);
 void exec_damage_small_land(DAMAGE* a0, f32 a1);
 void exec_damage_small_tornado(DAMAGE* a0, f32 a1);
 BTLOBJ(BTLOBJ* a0, OBJENTRY* a1, u32 a2, FVector* a3, f32 a4);
 u64 _OVR_is_withstand(DAMAGE* a0);
 void add_damage(DAMAGE* a0);
 u64 _turn_to_target_range(f32 a0, TARGET* a1);
 u64 _turn_to_target(f32 a0, TARGET* a1);
 void _OVR__dead(void);
 void sys_dead(void);
 void dead(void);
 u64 _OVR_is_star(void);
 u64 is_damage_motion(void);
 u64 is_reflect_motion(void);
 void _OVR_exec_damage(DAMAGE* a0);
 void exec_damage_large(DAMAGE* a0, f32 a1);
 void blow(FVector* a0);
 void exec_damage_blow(DAMAGE* a0, s32 a1, s32 a2, f32 a3, f32 a4);
 void exec_damage_small(DAMAGE* a0, f32 a1);
 void exec_damage_hitback(DAMAGE* a0, f32 a1);
 void _OVR_exec_damage_reaction(DAMAGE* a0);
 void _OVR_exec_reflect_bg(ATTACK* a0);
 void reset_tornado(void);
 void exec_reflect_default(ATTACK* a0, ATTACK* a1, s32 a2, f32 a3);
 void bind_hitmark(PAX* a0, s32 a1);
 void turn_to_target(f32 a0);
 void turn_to_target_range(f32 a0);
 u64 turn_to_lockon(f32 a0);
 u64 turn_to_lockon_range(f32 a0);
 u64 _OVR_add_hp(s32 a0, s32 a1, bool a2);
 void start_mpdrive(f32 a0);
 u64 add_mp(s32 a0, bool a1);
 void Each(BTLOBJ* a0);
 void tornado(ATTACK* a0, bool a1);
};

class BTLOBJ> {
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
 void exec_reflect_bg(BTLOBJ* a0, ATTACK* a1);
 void add_hp(BTLOBJ* a0, s32 a1, s32 a2, bool a3);
};
