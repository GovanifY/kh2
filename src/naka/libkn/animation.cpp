#include "animation.hpp"

namespace kn {


s32 AnimationWork::getNext() const {
    return (s32)reinterpret_cast<const AnimationWorkLayout*>(this)->next;
}
void AnimationWork::setNext(AnimationWork* v) {
    reinterpret_cast<AnimationWorkLayout*>(this)->next = v;
}
}  // namespace kn
