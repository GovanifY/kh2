#pragma once

#include "../../common/types.h"

namespace kn {

    class AnimationWork {
    public:
        s32 getNext() const;
        void setNext(AnimationWork* v);
    };

}  // namespace kn

