#pragma once

#include "../../common/types.h"

namespace dk {

struct SpriteLayout {
    char _pad0[368];
    s32 posX;
    s32 posY;
    s32 offsetX;
    s32 offsetY;
};

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
