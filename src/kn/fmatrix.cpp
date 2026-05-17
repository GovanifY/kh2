#include "fmatrix.hpp"

namespace kn {

class FVector;



extern "C" f32 func_0011c050(...);
extern "C" u32 func_002f4148(...);

u32 FMatrix::rotateX(f32 a1) {
    u32 s0 = (u32)this;
    if (a1 == 0.0f) return s0;
    f32 f0 = func_0011c050();
    ((u32 (*)(f32, u32, u32))func_002f4148)(f0, s0, s0);
    return s0;
}

extern "C" u32 func_002f41f0(...);
extern "C" u32 func_002f40a0(...);

u32 FMatrix::rotateY(f32 a1) {
    u32 s0 = (u32)this;
    if (a1 == 0.0f) return s0;
    f32 f0 = func_0011c050();
    ((u32 (*)(f32, u32, u32))func_002f41f0)(f0, s0, s0);
    return s0;
}

u32 FMatrix::rotateZ(f32 a1) {
    u32 s0 = (u32)this;
    if (a1 == 0.0f) return s0;
    f32 f0 = func_0011c050();
    ((u32 (*)(f32, u32, u32))func_002f40a0)(f0, s0, s0);
    return s0;
}

}  // namespace kn
