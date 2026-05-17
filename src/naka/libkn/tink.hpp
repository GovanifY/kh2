#pragma once

#include "../../common/types.h"

class Friend;
class FriendParam;
class Tink;

namespace kn {

    class Tink {
    public:
     Tink(Tink* a0, Friend* a1, FriendParam* a2);
     ~Tink();
    };

}  // namespace kn

