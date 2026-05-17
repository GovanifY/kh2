#ifndef KH2_SRC_SUGI_ACTION_CARD_HPP
#define KH2_SRC_SUGI_ACTION_CARD_HPP

#include "../common/types.h"

class ACTION_CARD;
class OBJ;

namespace Ts {

    class ACTION_CARD {
    public:
     void start(OBJ* a0);
     void end(OBJ* a0);
     void calc_movement(OBJ* a0);
     void SetSpec(f32 a0, f32 a1, f32 a2, f32 a3, f32 a4, f32 a5, f32 a6);
     ~ACTION_CARD();
    };

}  // namespace Ts

#endif
