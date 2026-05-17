#pragma once

#include "../../common/types.h"

class GAUGE_ENEMY;

namespace dk {

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

}  // namespace dk

