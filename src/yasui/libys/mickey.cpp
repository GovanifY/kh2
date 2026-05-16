#include "types.h"


namespace YS {

} // namespace YS

class ATTACK;
class ATTACKPARAM;
class ATTACK_WORK;
class BTLOBJ;
class COMMAND_ELEM;
class DAMAGE;
class OBJ;
class PARTY;
class PLAYER;
class STDOBJ;
class UNIT_DATA_OBJ;
class UNIT_GROUP;

class MICKEY {
public:
 void _OVR_pre_exec(void);
 void _OVR_exec(void);
 void _OVR_exec_command_player(COMMAND_ELEM* a0);
 void ResetChargeCallback(OBJ* a0);
 void recov_holylight(void);
 void recov_elixir(void);
 void ReadRequest(void);
 void Start(void);
 u64 IsExist(void);
};

class MICKEY> {
public:
 void initialize(OBJ* a0);
 void pre_exec(OBJ* a0);
 void control(OBJ* a0);
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
 void debug_exec(OBJ* a0);
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
 void attack(PARTY* a0);
 void ability(PARTY* a0);
 void is_wish_dir(PARTY* a0);
 void menu_in(PARTY* a0);
 void menu_out(PARTY* a0);
 void make_movement(PLAYER* a0);
 void exec_command_player(PLAYER* a0, COMMAND_ELEM* a1);
 void get_lockon_pos(PLAYER* a0);
};
