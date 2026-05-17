#pragma once

#include "../../common/types.h"

class ALLOCATOR;
class BgObj;
class BgObjPos;
class FMatrix;
class FVector;
class MapFile;
struct TASK;
class TYPE;
class uchar;

namespace dk {

    class BgObj {
    public:
     void setBoundingBox(FMatrix* a0);
     void calcMotionBoundingBox(void);
     void setColor(uchar a0, uchar a1, uchar a2);
     void ExecTask(TASK* a0);
     void ExecTaskFinalizer(TASK* a0);
     void DestroyTask(TASK* a0);
     void DestroyTaskFinalizer(TASK* a0);
     void DrawTask(TASK* a0);
     void ExecAllTask(TASK* a0);
     void ExecAllTaskFinalizer(TASK* a0);
     void calcMotion(void);
     void move(void);
     void draw(void);
     BgObj(BgObj* a0, BgObjPos* a1, u32 a2, FVector* a3, FVector* a4, FVector* a5, s32 a6, s32 a7, s32 a8, u32 a9, u32 a10);
     ~BgObj();
     bool isModelLod(void);
     bool isPartsLod(void);
     void start(void);
     void init(ALLOCATOR* a0, MapFile* a1);
     void stop(void);
     void hideGroup(u32 a0);
     void showGroup(u32 a0);
     void setBaseColorAll(uchar a0, uchar a1, uchar a2);
     void setColorAll(uchar a0, uchar a1, uchar a2);
     void setAnimationSpeedRatioAll(TYPE a0, f32 a1);
     s32 getBop(u32 a0);
     void showBgObjNumber(s32 a0);
     void hideBgObjNumber(s32 a0);
     u64 isExistGroup(s32 a0);
    };

}  // namespace dk

