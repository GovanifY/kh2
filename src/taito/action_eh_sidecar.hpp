#ifndef KH2_SRC_TAITO_ACTION_EH_SIDECAR_HPP
#define KH2_SRC_TAITO_ACTION_EH_SIDECAR_HPP

#include "../common/types.h"

class ACTION_EH_SIDECAR;
class OBJ;

namespace Ti {

    class ACTION_EH_SIDECAR {
    public:
     void start(OBJ* a0);
     void control(OBJ* a0);
     void calc_movement(OBJ* a0);
     ~ACTION_EH_SIDECAR();
    };

}  // namespace Ti

#endif
