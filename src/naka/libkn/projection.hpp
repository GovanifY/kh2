#ifndef KH2_SRC_NAKA_LIBKN_PROJECTION_HPP
#define KH2_SRC_NAKA_LIBKN_PROJECTION_HPP

#include "../../common/types.h"

namespace kn {

    class Projection {
    public:
        enum WorH { WOR_H0 = 0 };
        ~Projection();
        u32 getViewClipGsMatrix();
        f32 getFOV(WorH) const;
        f32 getScreenZ() const;
    };

}  // namespace kn

#endif
