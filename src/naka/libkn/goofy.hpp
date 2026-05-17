#ifndef KH2_SRC_NAKA_LIBKN_GOOFY_HPP
#define KH2_SRC_NAKA_LIBKN_GOOFY_HPP

#include "../../common/types.h"

class Friend;
class FriendAction;
class FriendParam;
class Goofy;
class TARGET;

namespace kn {

    class Goofy {
    public:
     Goofy(Goofy* a0, Friend* a1, FriendParam* a2);
     ~Goofy();
     u64 rush(FriendAction* a0, TARGET* a1, void** a2, bool a3);
     void blade(FriendAction* a0, TARGET* a1, void** a2, bool a3);
    };

}  // namespace kn

#endif
