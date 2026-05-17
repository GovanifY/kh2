#pragma once

#include "../../common/types.h"

namespace kn {

struct ProjectionLayout {
    char _pad0[64];
    f32 screenZ;
};

    class Projection {
    public:
        enum WorH { WOR_H0 = 0 };
        ~Projection();
        u32 getViewClipGsMatrix();
        f32 getFOV(WorH) const;
        f32 getScreenZ() const;
    };

}  // namespace kn
