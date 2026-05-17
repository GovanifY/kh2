#ifndef KH2_SRC_HARATA_LIBDK_SHAKE_HPP
#define KH2_SRC_HARATA_LIBDK_SHAKE_HPP

#include "../../common/types.h"

namespace dk {

class Shake {
public:
    void start(s32 a0, f32 a1, f32 a2, f32 a3, f32 a4);
    void calc(f32 a0);
    void exec(void);
};

}  // namespace dk

#endif
