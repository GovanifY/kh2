#ifndef KH2_SRC_TAITO_MG_JUMP_GIMOBJ_HPP
#define KH2_SRC_TAITO_MG_JUMP_GIMOBJ_HPP

#include "../common/types.h"

class FVector;
class MGJumpGimObj;
class OBJENTRY;

namespace Ti {

    class MGJumpGimObj {
    public:
     void _OVR_exec(void);
     void _OVR_begin(void);
     MGJumpGimObj(MGJumpGimObj* a0, OBJENTRY* a1, FVector* a2, f32 a3);
     u64 is_trigger(void);
     void burst(void);
     double get_top_pos(void);
     u16 get_reset_stage_id(void);
    };

}  // namespace Ti

#endif
