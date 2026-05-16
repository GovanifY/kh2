#include "types.h"


namespace YS {

} // namespace YS

class BTLOBJ;
class FVector;
class OBJ;
class OBJENTRY;
class PARAM;
class PRIZE;
class PRIZEEFFECT;
class PRIZEOBJ;
class STDOBJ;
class UNIT_DATA_OBJ;
class UNIT_GROUP;

class PRIZE {
public:
 void get_common(BTLOBJ* a0, PRIZEEFFECT* a1);
 void _OVR_check_get(PRIZEEFFECT* a0);
 PRIZE(PRIZE* a0, OBJENTRY* a1, s32 a2, u32 a3);
 ~PRIZE();
 void appear(PARAM* a0, FVector* a1);
 void Init(void);
 void Read(void);
 void Appear(FVector* a0, s32 a1);
 void ClearAll(void);
 u64 CanGet(BTLOBJ* a0, FVector* a1, f32 a2, f32 a3);
 void CheckGetGauge(PRIZEEFFECT* a0, f32 a1, s32 a2);
 void AladdinDrain(void);
 u32 GetAppearNum(void);
};

class PRIZE> {
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
 void voice(STDOBJ* a0, s32 a1, s32 a2);
 void check_get(PRIZEOBJ* a0, PRIZEEFFECT* a1);
};
