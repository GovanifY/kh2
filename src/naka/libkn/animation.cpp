#include "types.h"

namespace kn {
class AnimationWork {
public:
    s32 getNext() const;
    void setNext(AnimationWork* v);
};

struct AnimationWorkLayout {
    char _pad0[28];
    AnimationWork* next;
};

s32 AnimationWork::getNext() const {
    return (s32)reinterpret_cast<const AnimationWorkLayout*>(this)->next;
}
void AnimationWork::setNext(AnimationWork* v) {
    reinterpret_cast<AnimationWorkLayout*>(this)->next = v;
}
}  // namespace kn
