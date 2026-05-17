#ifndef KH2_SRC_YASUI_LIBYS_SIGNAL_HPP
#define KH2_SRC_YASUI_LIBYS_SIGNAL_HPP

#include "../../common/types.h"

class OBJ;
struct TASK;

namespace YS {

    class SIGNAL {
    public:
     void ClearReserve(s32 a0);
     u64 Call(s32 a0, s32 a1);
     void Exec(TASK* a0);
     void Init(void);
     void ReserveHp(OBJ* a0, f32 a1, s32 a2, s32 a3);
     void ReserveMinHp(OBJ* a0, s32 a1, s32 a2);
    };

}  // namespace YS

#endif
