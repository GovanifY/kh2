#include "../../common/types.h"


namespace YS {

} // namespace YS

class OBJ;
class OBJENTRY;
class PARTY;
class STDOBJ;
class UNIT_DATA_OBJ;
class UNIT_GROUP;
class WEAPON;

class WEAPON {
public:
 u64 locus(void);
 void appear(void);
 void _OVR_exec(void);
 void _OVR_leave(void);
 WEAPON(WEAPON* a0, OBJENTRY* a1, PARTY* a2, s32 a3, s32 a4, s32 a5);
 void force_destroy(void);
 u64 is_equip(void);
};

class WEAPON> {
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
 u32 get_data_priority(OBJ* a0);
 void is_control(OBJ* a0);
 void hide(OBJ* a0);
 void show(OBJ* a0);
 void attack_combo_start(STDOBJ* a0);
 void attack_on(STDOBJ* a0, s32 a1, s32 a2, STDOBJ* a3, s32 a4);
 void voice(STDOBJ* a0, s32 a1, s32 a2);
};
