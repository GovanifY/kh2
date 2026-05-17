#ifndef KH2_SRC_TAITO_MG_HACHIMITSU_GIMOBJ_HPP
#define KH2_SRC_TAITO_MG_HACHIMITSU_GIMOBJ_HPP

#include "../common/types.h"

class FVector;
class MGHachimitsuGimObj;
class OBJENTRY;

namespace Ti {

    class MGHachimitsuGimObj {
    public:
     MGHachimitsuGimObj(MGHachimitsuGimObj* a0, OBJENTRY* a1, FVector* a2, f32 a3);
    };

}  // namespace Ti

#endif
