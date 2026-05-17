#ifndef KH2_SRC_KN_FMATRIX_HPP
#define KH2_SRC_KN_FMATRIX_HPP

#include "../common/types.h"

namespace kn {

class FVector;

    class FMatrix {
       public:
        u32 rotateX(f32);
        u32 rotateY(f32);
        u32 rotateZ(f32);
    };

}  // namespace kn

#endif
