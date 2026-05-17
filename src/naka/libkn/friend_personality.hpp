#ifndef KH2_SRC_NAKA_LIBKN_FRIEND_PERSONALITY_HPP
#define KH2_SRC_NAKA_LIBKN_FRIEND_PERSONALITY_HPP

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

#endif
