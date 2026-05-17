#pragma once

#include "../../common/types.h"

class MODE;
class OBJ;
class PartsSelector;

namespace kn {

    class PartsSelector {
    public:
     PartsSelector(PartsSelector* a0, OBJ* a1, MODE a2);
     ~PartsSelector();
     void toggle(s32 a0);
     void init(void);
    };

}  // namespace kn

