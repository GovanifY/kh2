#ifndef KH2_SRC_NAKA_LIBKN_RIKU_HPP
#define KH2_SRC_NAKA_LIBKN_RIKU_HPP

#include "../../common/types.h"

class Friend;
class FriendAction;
class FriendParam;
class Riku;
class TARGET;

namespace kn {

    class Riku {
    public:
     Riku(Riku* a0, Friend* a1, FriendParam* a2);
     ~Riku();
     void idle(FriendAction* a0, TARGET* a1, void** a2, bool a3);
     void move(FriendAction* a0, TARGET* a1, void** a2, bool a3);
    };

}  // namespace kn

#endif
