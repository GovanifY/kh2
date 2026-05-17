#pragma once

#include "../../common/types.h"

class SHEET;

namespace YS {

    class ABILITY {
    public:
     void set_level(void);
     void init(SHEET* a0);
     void set_item(s32 a0);
     void check(void);
     u8 get_level(s32 a0);
    };

}  // namespace YS

