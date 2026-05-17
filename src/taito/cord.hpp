#ifndef KH2_SRC_TAITO_CORD_HPP
#define KH2_SRC_TAITO_CORD_HPP

#include "../common/types.h"

class Cord;

namespace Ti {

    class Cord {
    public:
     Cord();
     ~Cord();
     void init(void);
     void step(f32 a0, s32 a1);
     void add_vertical_force(f32 a0, f32 a1);
     double get_vertical_pos(f32 a0);
     double get_length(void);
    };

}  // namespace Ti

#endif
