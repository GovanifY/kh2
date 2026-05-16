#include "types.h"


namespace dk {

} // namespace dk

class GAUGE_ENEMY;

class GAUGE_ENEMY {
public:
 void updateHP(void);
 void update(void);
 void cure(s32 a0);
 void create(void);
 void end(void);
 void damage(s32 a0);
 ~GAUGE_ENEMY();
};

void gauge_enemy(s32 a0);
