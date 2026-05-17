#pragma once

#include "../../common/types.h"

class FVector;

namespace kn {

class FMatrix {
public:
 u32 rotateX(f32);
 u32 rotateY(f32);
 u32 rotateZ(f32);
 void inverse_salas(void);
 double determinant33(float* a0);
 double cofactor(s32 a0, s32 a1);
 double inverse44(void);
 void rotate(FVector* a0, f32 a1);
 void translate(FVector* a0);
 void toRot(FVector* a0);
 void inverse(void);
 s32 dump(void);
};

}  // namespace kn

