#ifndef KH2_SRC_NAKA_LIBKN_MULAN_HPP
#define KH2_SRC_NAKA_LIBKN_MULAN_HPP

#include "../../common/types.h"

class Friend;
class FriendAction;
class FriendParam;
class Mulan;
class TARGET;

namespace kn {

    class Mulan {
    public:
     Mulan(Mulan* a0, Friend* a1, FriendParam* a2);
     ~Mulan();
     void mushufire(FriendAction* a0, TARGET* a1, void** a2, bool a3);
     void flametongue(FriendAction* a0, TARGET* a1, void** a2, bool a3);
    };

}  // namespace kn

#endif
