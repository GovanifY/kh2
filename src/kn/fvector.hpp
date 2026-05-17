#ifndef KH2_KN_FVECTOR_HPP
#define KH2_KN_FVECTOR_HPP

#include "../common/types.h"

namespace kn {

struct __attribute__((aligned(16))) V4 {
    u32 x;
    u32 y;
    u32 z;
    u32 w;
};

struct __attribute__((aligned(16))) FVector {
    u32 x;
    u32 y;
    u32 z;
    u32 w;

    inline FVector& operator=(const FVector& rhs) {
        if (this == &rhs) {
            return *this;
        }
        asm("lq $8, 0(%1);"
            "sq $8, 0(%0);"
            :
            : "r"(this), "r"(&rhs)
            : "t0");
        return *this;
    }
};

}  // namespace kn

#endif  // KH2_KN_FVECTOR_HPP
