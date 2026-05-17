#ifndef KH2_SRC_YASUI_LIBYS_VACUUM_HPP
#define KH2_SRC_YASUI_LIBYS_VACUUM_HPP

#include "../../common/types.h"

class FVector;
class VACUUM;

namespace YS {

    class VACUUM {
    public:
     VACUUM(VACUUM* a0, FVector* a1, f32 a2);
     ~VACUUM();
     void Init(void);
     void Exit(void);
    };

}  // namespace YS

#endif
