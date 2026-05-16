#include "types.h"


namespace kn {

} // namespace kn

class ALLOCATOR;
class FMatrix;
class FVector;
class IKAdjust;
class ModelObj;
class Motion;
class MotionContext;
class ToFace;

class Motion {
public:
 Motion(Motion* a0, void* a1);
 ~Motion();
 void clearIKAdjustResult(IKAdjust* a0);
 void calcIKJoint(FVector* a0, FVector* a1, f32 a2, f32 a3, s32 a4, FMatrix* a5, FMatrix* a6, f32 a7, f32 a8, FVector* a9);
 void calc(ModelObj* a0, FMatrix* a1, MotionContext* a2, MotionContext* a3, f32 a4, ToFace* a5, IKAdjust* a6, s32 a7);
 void calc(ModelObj* a0, FMatrix* a1, MotionContext* a2, MotionContext* a3, f32 a4, ToFace* a5, IKAdjust* a6);
 void destroyMotionContext(ModelObj* a0, ALLOCATOR* a1, MotionContext* a2);
};
