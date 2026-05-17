#pragma once

#include "../common/types.h"

class MUSICAL_GAUGE3;

namespace sa {

    class MUSICAL_GAUGE3 {
    public:
     void calcCursorPos(void);
     void update(void);
     void create(void);
     void init(void);
     ~MUSICAL_GAUGE3();
    };

}  // namespace sa

