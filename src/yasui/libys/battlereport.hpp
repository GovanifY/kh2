#ifndef KH2_SRC_YASUI_LIBYS_BATTLEREPORT_HPP
#define KH2_SRC_YASUI_LIBYS_BATTLEREPORT_HPP

#include "../../common/types.h"

class BATTLE_REPORT;

namespace YS {

    class BATTLE_REPORT {
    public:
     BATTLE_REPORT();
     void IncrementFriendRecov(void);
     void IncrementFormCount(s32 a0);
     void IncrementSummonCount(s32 a0);
     u64 IsSecretMovie(void);
     u64 IsFMSecretMovie(void);
     u64 GetResultPicture(void);
    };

}  // namespace YS

#endif
