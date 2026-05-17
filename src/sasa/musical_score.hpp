#pragma once

#include "../common/types.h"

class MUSICAL_SCORE;
class Sprite;

namespace sa {

    class MUSICAL_SCORE {
    public:
     void destroy(void);
     void update(void);
     void create(s32 a0, int* a1, int* a2, s32 a3);
     void setBaseParent(Sprite* a0, s32 a1);
     ~MUSICAL_SCORE();
    };

}  // namespace sa

