#ifndef KH2_SRC_NAKA_LIBKN_JACK_HPP
#define KH2_SRC_NAKA_LIBKN_JACK_HPP

#include "../../common/types.h"

class Friend;
class FriendAction;
class FriendParam;
class Jack;
class TARGET;

namespace kn {

    class Jack {
    public:
     Jack(Jack* a0, Friend* a1, FriendParam* a2);
     ~Jack();
     void slidingfire(FriendAction* a0, TARGET* a1, void** a2, bool a3);
     void backstepblizzard(FriendAction* a0, TARGET* a1, void** a2, bool a3);
     void airthunder(FriendAction* a0, TARGET* a1, void** a2, bool a3);
    };

}  // namespace kn

#endif
