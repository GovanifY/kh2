#ifndef KH2_SRC_TAITO_ACTION_AL_ESCAPE_HPP
#define KH2_SRC_TAITO_ACTION_AL_ESCAPE_HPP

#include "../common/types.h"

class ACTION_AL_ESCAPE;
class OBJ;

namespace Ti {

    class ACTION_AL_ESCAPE {
    public:
     void start(OBJ* a0);
     void control(OBJ* a0);
     void calc_movement(OBJ* a0);
     ~ACTION_AL_ESCAPE();
     ACTION_AL_ESCAPE();
    };

}  // namespace Ti

#endif
