#include "../../common/types.h"


namespace YS {

} // namespace YS

class ACTOR;
class FVector;
class OBJ;
class OBJENTRY;
class UNIT_DATA_OBJ;
class UNIT_GROUP;

class ACTOR {
public:
 void _OVR_debug_exec(void);
 ACTOR(ACTOR* a0, OBJENTRY* a1, u32 a2, FVector* a3, f32 a4);
 u16 GetHiModelEntryId(s32 a0);
};

class ACTOR> {
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
 void debug_exec(OBJ* a0);
};
