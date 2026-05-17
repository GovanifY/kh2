#pragma once

#include "../../common/types.h"

namespace kn {

class ALLOCATOR;
class AnimationWork;
class DMA_SET_TAG;
class DrawParam;
class FMatrix;
class ModelObj;
class ProjectionCamera;

class ModelBG {
public:
    ModelBG(ModelBG* a0, void* a1);
    ~ModelBG();
    void destroyModelObj(ALLOCATOR* a0, ModelObj* a1);
    u16 getGroupNum(void);
    void setDisplayFlag(char* a0, short* a1);
    void draw(ProjectionCamera* a0, DMA_SET_TAG** a1, DrawParam* a2, char* a3, AnimationWork* a4, bool a5, FMatrix* a6);
    void drawOnShadow(ProjectionCamera* a0, DMA_SET_TAG** a1, DrawParam* a2, char* a3, bool a4, FMatrix* a5);
    s32 getDrawPolygonNum(char* a0);
    s32 getShadowPolygonNum(short* a0);
    u64 drawCommon(ProjectionCamera* a0, DrawParam* a1, char* a2, AnimationWork* a3, bool a4, FMatrix* a5);
};

class ModelBG_ {
public:
    u16 getGroupIndex(s32 a0, s32 a1);
};

}  // namespace kn

