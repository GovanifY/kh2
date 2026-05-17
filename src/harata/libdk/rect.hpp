#ifndef KH2_SRC_HARATA_LIBDK_RECT_HPP
#define KH2_SRC_HARATA_LIBDK_RECT_HPP

#include "types.h"

namespace dk {

class RectParamBase {
public:
    void setXY(s16 x, s16 y);
    void setZ(u32 v);
};

class RectBase {
public:
    void setGsPrim(u64 v);
    void setGsFrame(u64 v);
    void setGsZbuf(u64 v);
    void setGsTest(u64 v);
    void setGsAlpha(u64 v);
    void setGsTex0(u64 v);
    void setGsTex1(u64 v);
};

}  // namespace dk

#endif
