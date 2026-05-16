#include "types.h"


namespace kn {

} // namespace kn

class FVector;

class FMatrix {
public:
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
