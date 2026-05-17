#ifndef KH2_SRC_NAKA_LIBKN_DONALD_HPP
#define KH2_SRC_NAKA_LIBKN_DONALD_HPP

#include "../../common/types.h"

class Donald;
class Friend;
class FriendParam;

namespace kn {

    class Donald {
    public:
     Donald(Donald* a0, Friend* a1, FriendParam* a2);
     ~Donald();
    };

}  // namespace kn

#endif
