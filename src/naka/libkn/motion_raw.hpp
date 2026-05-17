#ifndef KH2_SRC_NAKA_LIBKN_MOTION_RAW_HPP
#define KH2_SRC_NAKA_LIBKN_MOTION_RAW_HPP

#include "../../common/types.h"

class ALLOCATOR;
class FMatrix;
class FVector;
class IKAdjust;
class ModelObj;
class MotionRAW;
class ToFace;

namespace kn {

    class MotionRAW {
    public:
     MotionRAW(MotionRAW* a0, void* a1);
     ~MotionRAW();
     u32 getLength(void);
     void calc(ModelObj* a0, FMatrix* a1, f32 a2, ToFace* a3, IKAdjust* a4);
     u64 allocIKInfo(ModelObj* a0, ALLOCATOR* a1);
     void getBoundingBox(FVector* a0, FVector* a1);
     u64 getPosition(FMatrix* a0, f32 a1);
     double getLoopTop(void);
    };

}  // namespace kn

#endif
