#ifndef KH2_SRC_NAKA_LIBKN_ANIMATION_HPP
#define KH2_SRC_NAKA_LIBKN_ANIMATION_HPP

#include "../../common/types.h"

namespace kn {

    class AnimationWork {
    public:
        s32 getNext() const;
        void setNext(AnimationWork* v);
    };

}  // namespace kn

#endif
