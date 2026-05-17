#ifndef KH2_SRC_HARATA_LIBDK_FT4_HPP
#define KH2_SRC_HARATA_LIBDK_FT4_HPP

#include "types.h"

namespace dk {

class Ft4Base {
public:
    void setRot(f32 v);
    void setCenterXY(s32 x, s32 y);
    void setGsTex0(u64 v);
    void setGsTest(u64 v);
    void setGsPrim(u64 v);
};

}  // namespace dk

#endif
