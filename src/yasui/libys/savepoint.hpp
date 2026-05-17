#ifndef KH2_SRC_YASUI_LIBYS_SAVEPOINT_HPP
#define KH2_SRC_YASUI_LIBYS_SAVEPOINT_HPP

#include "../../common/types.h"

class FVector;
class OBJENTRY;
class SAVEPOINT;

namespace YS {

    class SAVEPOINT {
    public:
     SAVEPOINT(SAVEPOINT* a0, OBJENTRY* a1, FVector* a2, f32 a3);
     u64 initialize(OBJENTRY* a0, FVector* a1, f32 a2);
     void EffectOff(void);
     void recover(void);
    };

}  // namespace YS

#endif
