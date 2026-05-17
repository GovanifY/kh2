#pragma once

#include "../../common/types.h"

class ALLOCATOR;
class CollisionParam;
class FMatrix;
class FVector;
class Line;
class ObjOcc;

namespace dk {

    class ObjOcc {
    public:
     void setup(void* a0, s32 a1);
     void each(ObjOcc* a0);
     void setMatrix(FMatrix* a0);
     void disableWall(void);
     void destroy(void);
     void init(ALLOCATOR* a0);
     void exit(void);
     u64 collisionSphere(CollisionParam* a0);
     u64 collisionDown(CollisionParam* a0, float* a1);
     u64 intersectLine(Line* a0, FVector* a1, ushort* a2, u32 a3, u32 a4, bool a5, ObjOcc** a6, s32 a7, s32 a8);
     void drawPolygon(void);
    };

}  // namespace dk

