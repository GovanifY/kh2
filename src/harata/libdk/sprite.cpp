#include "sprite.hpp"

extern u32 YI_SEQUENCE_GetActiveXY(void*, s32*, s32*) asm("_ZN2YI8SEQUENCE11GetActiveXYEPiS1_");

namespace dk {

struct SpriteLayout {
    char _pad0[368];
    s32 posX;
    s32 posY;
    s32 offsetX;
    s32 offsetY;
};

u32 Sprite::getSeqActiveXY(s32& x, s32& y) {
    return YI_SEQUENCE_GetActiveXY(reinterpret_cast<u8*>(this) + 24u, &x, &y);
}

void Sprite::getSeqActiveXYAddOffset(s32& x, s32& y) {
    YI_SEQUENCE_GetActiveXY(reinterpret_cast<u8*>(this) + 24u, &x, &y);
    SpriteLayout* s = reinterpret_cast<SpriteLayout*>(this);
    x += s->offsetX;
    y += s->offsetY;
}

void Sprite::setPos(s32 x, s32 y) {
    SpriteLayout* s = reinterpret_cast<SpriteLayout*>(this);
    s->posX = x;
    s->posY = y;
}

void Sprite::getPos(s32& x, s32& y) {
    SpriteLayout* s = reinterpret_cast<SpriteLayout*>(this);
    x = s->posX;
    y = s->posY;
}

void Sprite::setOffsetPos(s32 x, s32 y) {
    SpriteLayout* s = reinterpret_cast<SpriteLayout*>(this);
    s->offsetX = x;
    s->offsetY = y;
}

void Sprite::getOffsetPos(s32& x, s32& y) {
    SpriteLayout* s = reinterpret_cast<SpriteLayout*>(this);
    x = s->offsetX;
    y = s->offsetY;
}

}  // namespace dk
