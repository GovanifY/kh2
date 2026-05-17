#ifndef KH2_SRC_YASUI_LIBYS_FADE_HPP
#define KH2_SRC_YASUI_LIBYS_FADE_HPP

#include "../../common/types.h"

namespace YS {

    class FADE {
    public:
     void start(f32 a0, f32 a1, f32 a2);
     u64 exec(void);
    };

}  // namespace YS

#endif
