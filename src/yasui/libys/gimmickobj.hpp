#ifndef KH2_SRC_YASUI_LIBYS_GIMMICKOBJ_HPP
#define KH2_SRC_YASUI_LIBYS_GIMMICKOBJ_HPP

#include "../../common/types.h"

class FVector;
class GIMMICKOBJ;
class OBJENTRY;

namespace YS {

    class GIMMICKOBJ {
    public:
     GIMMICKOBJ(GIMMICKOBJ* a0, OBJENTRY* a1, FVector* a2, f32 a3);
    };

}  // namespace YS

#endif
