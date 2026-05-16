#include "types.h"


namespace kn {

} // namespace kn

class ALLOCATOR;
class FMatrix;
class FVector;
class IKAdjust;
class ModelObj;
class MotionPrototype0;
class MotionPrototype0RAWConstraint;
class MotionPrototype0RAWFcurve;
class MotionPrototype0RAWLimiter;
class ToFace;

class MotionPrototype0 {
public:
 MotionPrototype0(MotionPrototype0* a0, void* a1);
 ~MotionPrototype0();
 void calcLimitValue(MotionPrototype0RAWLimiter* a0, FVector* a1, FVector* a2);
 void getTimeIndex(f32 a0, int* a1, int* a2);
 double calcFcurveValue(MotionPrototype0RAWFcurve* a0, s32 a1, s32 a2, f32 a3);
 void setConstantValue(ModelObj* a0);
 void setFcurveValue(ModelObj* a0, f32 a1);
 void getCnsPos(ModelObj* a0, s32 a1, s32 a2, FVector* a3, FMatrix* a4, FVector* a5);
 void getCnsPos(ModelObj* a0, MotionPrototype0RAWConstraint* a1, FVector* a2, FMatrix* a3, FVector* a4);
 double evalExpression(ModelObj* a0, u16 a1);
 void calcMatrix(ModelObj* a0, FMatrix* a1, ToFace* a2, IKAdjust* a3);
 void calcMatrix_ignoreScale(ModelObj* a0, FMatrix* a1, ToFace* a2, IKAdjust* a3);
 void setConstraintActivation(f32 a0);
 u32 getLength(void);
 void calc(ModelObj* a0, FMatrix* a1, f32 a2, ToFace* a3, IKAdjust* a4);
 s32 allocIKInfo(ModelObj* a0, ALLOCATOR* a1);
 void getBoundingBox(FVector* a0, FVector* a1);
 u64 getPosition(FMatrix* a0, f32 a1);
 double getLoopTop(void);
 s32 getHrc(ModelObj* a0, s32 a1);
 s32 scale(ModelObj* a0, s32 a1);
 s32 rotation(ModelObj* a0, s32 a1);
 s32 translation(ModelObj* a0, s32 a1);
 s32 lmatrix(ModelObj* a0, s32 a1);
 s32 gmatrix(ModelObj* a0, s32 a1);
};
