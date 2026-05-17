#pragma once

#include "../../common/types.h"

namespace kn {
class FVector;
}

namespace dk {

class Line;

    class Aabbox {
    public:
        Aabbox(f32, f32, f32, f32, f32, f32);
        Aabbox(kn::FVector const&, kn::FVector const&);
        Aabbox(Line const&);
        void set(kn::FVector const&, kn::FVector const&);
        void set(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f);
    };

}  // namespace dk

