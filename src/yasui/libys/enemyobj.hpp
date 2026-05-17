#ifndef KH2_SRC_YASUI_LIBYS_ENEMYOBJ_HPP
#define KH2_SRC_YASUI_LIBYS_ENEMYOBJ_HPP

#include "../../common/types.h"

class ENEMYOBJ;
class FVector;
class OBJENTRY;

namespace YS {

    class ENEMYOBJ {
    public:
     ENEMYOBJ(ENEMYOBJ* a0, OBJENTRY* a1, FVector* a2, f32 a3);
    };

}  // namespace YS

#endif
