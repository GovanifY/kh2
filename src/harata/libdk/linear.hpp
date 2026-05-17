#ifndef KH2_SRC_HARATA_LIBDK_LINEAR_HPP
#define KH2_SRC_HARATA_LIBDK_LINEAR_HPP

#include "../../common/types.h"

namespace dk {

    class Linear {
    public:
     void start(f32 a0, f32 a1, f32 a2);
     u64 execFixed(void);
     u64 exec(void);
    };

}  // namespace dk

#endif
