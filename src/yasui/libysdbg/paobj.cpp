#include "../../common/types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace YS {

} // namespace YS

class FMatrix;
class FVector;
class OBJ;
class OBJENTRY;
class PAOBJ;
class STDOBJ;
class UNIT_DATA_OBJ;
class UNIT_GROUP;

class PAOBJ {
public:
 PAOBJ(PAOBJ* a0, OBJENTRY* a1, FVector* a2, f32 a3, u32 a4);
 double get_weapon_matrix(s32 a0, FMatrix* a1);
 void set_weapon(s32 a0, s32 a1, PAOBJ* a2);
};

class PAOBJ> {
public:
 void pre_exec(OBJ* a0);
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
 void voice(STDOBJ* a0, s32 a1, s32 a2);
};
