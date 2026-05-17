#ifndef KH2_SRC_HARATA_LIBDK_SPRITE_HPP
#define KH2_SRC_HARATA_LIBDK_SPRITE_HPP

#include "types.h"

namespace dk {

class Sprite {
public:
    u32 getSeqActiveXY(s32&, s32&);
    void getSeqActiveXYAddOffset(s32&, s32&);
    void setPos(s32, s32);
    void getPos(s32&, s32&);
    void setOffsetPos(s32, s32);
    void getOffsetPos(s32&, s32&);
};

}  // namespace dk

#endif
