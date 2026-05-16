#include "types.h"


namespace kn {

} // namespace kn

class ALLOCATOR;
class AnimationWork;
class DMA_SET_TAG;
class DrawParam;
class FMatrix;
class FVector;
class ModelMulti;
class ModelObj;
class PART_NAME;
class ProjectionCamera;

class ModelMulti {
public:
 ModelMulti(ModelMulti* a0, void* a1);
 ~ModelMulti();
 s32 getModel(u32 a0);
 void getDistanceFromSkeleton(void);
 void getBoundingBox(FVector* a0, FVector* a1);
 void partName2matrixNo(PART_NAME a0);
 void getHrcNum(void);
 void getHrc(void);
 void destroyModelObj(ALLOCATOR* a0, ModelObj* a1);
 void calc(ModelObj* a0);
 s32 getGroupNum(void);
 void setDisplayFlag(char* a0, short* a1);
 void showPart(char* a0, s32 a1);
 void hidePart(char* a0, s32 a1);
 void setStealth(char* a0, s32 a1);
 void resetStealth(char* a0, s32 a1);
 void draw(ProjectionCamera* a0, DMA_SET_TAG** a1, DrawParam* a2, char* a3, AnimationWork* a4, bool a5, FMatrix* a6);
 void drawSilhouette(ProjectionCamera* a0, DMA_SET_TAG** a1, DrawParam* a2, char* a3, AnimationWork* a4, bool a5, FMatrix* a6);
 void drawOnShadow(ProjectionCamera* a0, DMA_SET_TAG** a1, DrawParam* a2, char* a3, bool a4, FMatrix* a5);
 s32 getGroupNumOffset(s32 a0);
};
