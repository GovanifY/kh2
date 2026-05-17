#pragma once

#include "../../common/types.h"

class ALLOCATOR;
class AnimationWork;
class DMA_SET_TAG;
class DrawParam;
class FMatrix;
class FVector;
class ModelObj;
class ModelSKL;
class PART_NAME;
class ProjectionCamera;
class Texture;
class Vif1PacketBuffer;

namespace kn {

    class ModelSKL {
    public:
     ModelSKL(ModelSKL* a0, void* a1);
     ~ModelSKL();
     void setDMATagBuffer(ModelObj* a0, void* a1);
     s32 getShadowData(void);
     double getDistanceFromSkeleton(void);
     void getBoundingBox(FVector* a0, FVector* a1);
     double getIKBias(s32 a0);
     u32 partName2matrixNo(PART_NAME a0);
     u16 getHrcNum(void);
     s32 getHrc(void);
     void destroyModelObj(ALLOCATOR* a0, ModelObj* a1);
     void calc(ModelObj* a0);
     s32 getGroupNum(void);
     void setDisplayFlag(char* a0, short* a1);
     u32 getParts(void);
     void showPart(char* a0, s32 a1);
     void hidePart(char* a0, s32 a1);
     void setStealth(char* a0, s32 a1);
     void resetStealth(char* a0, s32 a1);
     u64 draw(ProjectionCamera* a0, DMA_SET_TAG** a1, DrawParam* a2, char* a3, AnimationWork* a4, bool a5, FMatrix* a6);
     void drawOnShadow(ProjectionCamera* a0, DMA_SET_TAG** a1, DrawParam* a2, char* a3, bool a4, FMatrix* a5);
     s32 getDrawPolygonNum(char* a0);
     void setTexture(Vif1PacketBuffer* a0, s32 a1, AnimationWork* a2, Texture* a3);
     void setTexfade(Vif1PacketBuffer* a0, s32 a1, DrawParam* a2, AnimationWork* a3, bool a4, Texture* a5, Texture* a6);
     u64 drawNormal(ProjectionCamera* a0, DMA_SET_TAG** a1, DrawParam* a2, char* a3, AnimationWork* a4, bool a5, FMatrix* a6);
     u64 drawStealth(ProjectionCamera* a0, DMA_SET_TAG** a1, DrawParam* a2, char* a3, AnimationWork* a4, bool a5, FMatrix* a6);
     s32 getDMATagBufferSize(void);
     u64 drawSilhouette(ProjectionCamera* a0, DMA_SET_TAG** a1, DrawParam* a2, char* a3, AnimationWork* a4, bool a5, FMatrix* a6);
    };

}  // namespace kn

