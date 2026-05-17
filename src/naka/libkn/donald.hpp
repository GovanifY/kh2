#pragma once

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

