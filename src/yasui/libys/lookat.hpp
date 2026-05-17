#ifndef KH2_SRC_YASUI_LIBYS_LOOKAT_HPP
#define KH2_SRC_YASUI_LIBYS_LOOKAT_HPP

#include "../../common/types.h"

class FVector;
class OBJ;

namespace YS {

    class LOOKAT {
    public:
     void set_bone(OBJ* a0);
     double start(FVector* a0, f32 a1, u32 a2);
     double start(OBJ* a0, f32 a1, u32 a2);
     void release(f32 a0);
     void set_pos_limit_can_look(FVector* a0);
     void exec(void);
    };

}  // namespace YS

#endif
