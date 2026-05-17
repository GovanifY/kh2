#ifndef KH2_SRC_YASUI_LIBYS_JIGSAWPIECE_HPP
#define KH2_SRC_YASUI_LIBYS_JIGSAWPIECE_HPP

#include "../../common/types.h"

class FVector;
class JIGSAWPIECE;
class OBJENTRY;

namespace YS {

    class JIGSAWPIECE {
    public:
     void _OVR_initialize(void);
     void _OVR_exec(void);
     JIGSAWPIECE(JIGSAWPIECE* a0, OBJENTRY* a1, FVector* a2, f32 a3);
    };

}  // namespace YS

#endif
