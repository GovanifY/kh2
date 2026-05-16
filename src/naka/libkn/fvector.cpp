#include "types.h"


namespace kn {

} // namespace kn

class FVector;

class FVector {
public:
 double getLengthSquare(void);
 void scaleXYZ(f32 a0);
 FVector();
 FVector(FVector* a0, f32 a1, f32 a2, f32 a3, f32 a4);
};
