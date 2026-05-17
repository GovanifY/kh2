#pragma once

#include "../common/types.h"

namespace Tz {

class IMAGE;
class SEQUENCE;
class Sprite;

class MultiSeq {
public:
    void setNum(s32 a0, s32 a1, s32 a2);
    void update(void);
    void draw(void);
    void setLocalParentSeq(s32 a0, SEQUENCE* a1);
    void setExMode(s32 a0);
    void setParent(Sprite* a0);
    void InitWork(s32 a0);
    void InitSqd(s32 a0, void* a1, IMAGE* a2, s32 a3);
    MultiSeq();
    ~MultiSeq();
    void create(s32 a0, void* a1, IMAGE* a2, short* a3, s32 a4, s32 a5);
    u32 getNum(s32 a0);
    void setNextNum(s32 a0, s32 a1);
    void setMultiNum(short* a0, s32 a1, s32 a2);
    void setMultiNextNum(short* a0, s32 a1);
    void setOffsetPos(s32 a0, s32 a1);
    void setLocalOffsetPos(s32 a0, s32 a1, s32 a2);
    void setParamXYToOffset(Sprite* a0);
    void setLocalScaleXY(s32 a0, f32 a1, f32 a2);
    s32 getSequence(s32 a0);
};

}  // namespace Tz

