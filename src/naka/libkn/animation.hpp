#pragma once

#include "../../common/types.h"

namespace kn {

class AnimationWork;

struct AnimationWorkLayout {
    char _pad0[28];
    AnimationWork* next;
};

    class AnimationWork {
    public:
        s32 getNext() const;
        void setNext(AnimationWork* v);
    };

}  // namespace kn
