#ifndef KH2_SRC_HARATA_LIBDK_TURN_HPP
#define KH2_SRC_HARATA_LIBDK_TURN_HPP

#include "../../common/types.h"

class OBJ;

namespace dk {

    class Turn {
    public:
     void start(OBJ* a0, s32 a1, f32 a2, f32 a3);
     u64 exec(void);
    };

}  // namespace dk

#endif
