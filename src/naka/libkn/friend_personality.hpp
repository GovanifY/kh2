#pragma once

#include "../../common/types.h"

namespace kn {

class Friend;

    class FriendPersonality {
    public:
        f32 getBattleCancelDistance() const;
        void start_limit();
        void setObj(Friend* v);
    };

}  // namespace kn

