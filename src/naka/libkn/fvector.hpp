#ifndef KH2_SRC_NAKA_LIBKN_FVECTOR_HPP
#define KH2_SRC_NAKA_LIBKN_FVECTOR_HPP

#include "../../common/types.h"

class FVector;

namespace kn {

    class FVector {
    public:
     double getLengthSquare(void);
     void scaleXYZ(f32 a0);
     FVector();
     FVector(FVector* a0, f32 a1, f32 a2, f32 a3, f32 a4);
    };

}  // namespace kn

#endif
