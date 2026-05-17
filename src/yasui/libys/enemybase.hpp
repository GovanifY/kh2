#ifndef KH2_SRC_YASUI_LIBYS_ENEMYBASE_HPP
#define KH2_SRC_YASUI_LIBYS_ENEMYBASE_HPP

#include "../../common/types.h"

class ENEMYBASE;
class FVector;
class OBJENTRY;

namespace YS {

    class ENEMYBASE {
    public:
     void _OVR_initialize(void);
     void _OVR_leave(void);
     void _OVR__dead(void);
     ENEMYBASE(ENEMYBASE* a0, OBJENTRY* a1, FVector* a2, f32 a3);
    };

}  // namespace YS

#endif
