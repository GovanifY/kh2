#ifndef KH2_SRC_HARATA_LIBDK_DISPFRAME_HPP
#define KH2_SRC_HARATA_LIBDK_DISPFRAME_HPP

#include "../../common/types.h"

namespace dk {

    class DispFrame {
    public:
     void initShakeXYoffset(void);
     void setShakeXYoffset(s16 a0, s16 a1);
    };

}  // namespace dk

#endif
