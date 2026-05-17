#pragma once

#include "../../common/types.h"

class Friend;
class FriendParam;
class Pin;

namespace kn {

    class Pin {
    public:
     Pin(Pin* a0, Friend* a1, FriendParam* a2);
     ~Pin();
    };

}  // namespace kn

