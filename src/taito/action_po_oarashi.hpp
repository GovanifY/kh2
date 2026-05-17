#pragma once

#include "../common/types.h"

class ACTION_PO_OARASHI;
class OBJ;

namespace Ti {

    class ACTION_PO_OARASHI {
    public:
     void start(OBJ* a0);
     void calc_movement(OBJ* a0);
     ~ACTION_PO_OARASHI();
     ACTION_PO_OARASHI();
    };

}  // namespace Ti

