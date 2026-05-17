#ifndef KH2_SRC_HARATA_LIBDK_GAUGE_PARTY_HPP
#define KH2_SRC_HARATA_LIBDK_GAUGE_PARTY_HPP

#include "../../common/types.h"

class GAUGE_PARTY;
class OBJ;

namespace dk {

    class GAUGE_PARTY {
    public:
     u64 isAlertStart(void);
     u64 isAlertEnd(void);
     void calcHPStatus(void);
     s32 getGroup(void);
     void checkObj(void);
     void updateAction(void);
     void create(OBJ* a0, s32 a1, s32 a2);
     u64 checkMpDrawTrigger(void);
     ~GAUGE_PARTY();
     void reload(void);
     void damageSmall(void);
     void damageMiddle(void);
     void damageLarge(void);
     void cure(void);
    };

}  // namespace dk

#endif
