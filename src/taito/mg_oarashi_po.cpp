#include "types.h"


namespace Ti {

} // namespace Ti

class DAMAGE;
class FVector;
class MGOarashiPo;
class OBJENTRY;

class MGOarashiPo {
public:
 void _OVR_initialize(void);
 void _OVR_pre_exec(void);
 void calc_move_dir(void);
 void _OVR_exec(void);
 void separate(FVector* a0);
 void _OVR_exec_damage(DAMAGE* a0);
 MGOarashiPo(MGOarashiPo* a0, OBJENTRY* a1, FVector* a2, f32 a3);
 void combine(void);
};
