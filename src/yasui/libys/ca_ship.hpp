#ifndef KH2_SRC_YASUI_LIBYS_CA_SHIP_HPP
#define KH2_SRC_YASUI_LIBYS_CA_SHIP_HPP

#include "../../common/types.h"

class AREA;
class JUMPER;

namespace YS {

    class CA_SHIP {
    public:
     u64 IsSkipArea(AREA* a0, JUMPER* a1);
     void ArriveArea(AREA* a0);
     void ProgressCallback(s32 a0);
     u16 GetDisableReason(s32 a0, s32 a1);
     u64 IsDisableArea(s32 a0, s32 a1);
    };

}  // namespace YS

#endif
