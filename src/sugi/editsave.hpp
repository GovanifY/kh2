#pragma once

#include "../common/types.h"

class EDITSAVE;

namespace Ts {

    class EDITSAVE {
    public:
     EDITSAVE();
     ~EDITSAVE();
     s32 get_gumiship_plan(s32 a0);
     s32 get_tinyship_plan(s32 a0);
     void endian_read(void);
     void endian_write(void);
     s32 Get(void);
    };

}  // namespace Ts

