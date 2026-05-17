#ifndef KH2_SRC_HARATA_LIBDK_FRAME_HPP
#define KH2_SRC_HARATA_LIBDK_FRAME_HPP

#include "../../common/types.h"

class Frame;

namespace dk {

    class Frame {
    public:
     Frame();
     void setFrame(u16 a0, u32 a1, u16 a2, u16 a3);
     s32 widthToTW(u32 a0);
    };

}  // namespace dk

#endif
