#pragma once

#include "../../common/types.h"

class ALLOCATOR;
class AnimationWork;
class DMA_SET_TAG;
class DrawParam;
class FMatrix;
class FVector;
class Model;
class ModelObj;
class PART_NAME;
class ProjectionCamera;

namespace kn {

    class Model {
    public:
     Model(Model* a0, void* a1);
     ~Model();
     u64 getDMATagBufferSize(void);
     u64 getDistanceFromSkeleton(void);
     void getBoundingBox(FVector* a0, FVector* a1);
     u64 getIKBias(s32 a0);
     u64 partName2matrixNo(PART_NAME a0);
     u64 getHrcNum(void);
     u64 getHrc(void);
     void initModelObj(ModelObj* a0);
     void destroyModelObj(ALLOCATOR* a0, ModelObj* a1);
     u64 getGroupNum(void);
     u64 getParts(void);
     u64 drawSilhouette(ProjectionCamera* a0, DMA_SET_TAG** a1, DrawParam* a2, char* a3, AnimationWork* a4, bool a5, FMatrix* a6);
     u64 drawStealth(ProjectionCamera* a0, DMA_SET_TAG** a1, DrawParam* a2, char* a3, AnimationWork* a4, bool a5, FMatrix* a6);
     u64 drawOnShadow(ProjectionCamera* a0, DMA_SET_TAG** a1, DrawParam* a2, char* a3, bool a4, FMatrix* a5);
     void clearDisplayFlag(char* a0);
     void pushDisplayFlag(char* a0);
     void popDisplayFlag(char* a0);
     u64 getDrawPolygonNum(char* a0);
     void getParentEnvelope(s32 a0);
    };

}  // namespace kn

