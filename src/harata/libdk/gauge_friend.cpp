#include "types.h"


namespace dk {

} // namespace dk

class GAUGE_FRIEND;
class OBJ;

class GAUGE_FRIEND {
public:
 void createMpCircle(f32 a0);
 void createHpCircle(f32 a0, s32 a1);
 u64 getBaseSqNum(void);
 void upDown(void);
 void update(void);
 void reload(void);
 void damageSmall(void);
 void damageMiddle(void);
 void damageLarge(void);
 void cure(void);
 void create(OBJ* a0, s32 a1);
 ~GAUGE_FRIEND();
};
