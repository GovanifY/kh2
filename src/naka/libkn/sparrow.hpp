#ifndef KH2_SRC_NAKA_LIBKN_SPARROW_HPP
#define KH2_SRC_NAKA_LIBKN_SPARROW_HPP

#include "../../common/types.h"

class DAMAGE;
class Friend;
class FriendAction;
class FriendParam;
class Sparrow;
class TARGET;

namespace kn {

    class Sparrow {
    public:
     Sparrow(Sparrow* a0, Friend* a1, FriendParam* a2);
     ~Sparrow();
     void exec_damage(DAMAGE* a0);
     void deadendclimb(FriendAction* a0, TARGET* a1, void** a2, bool a3);
     void shadowsnipe(FriendAction* a0, TARGET* a1, void** a2, bool a3);
     void bonecrusher(FriendAction* a0, TARGET* a1, void** a2, bool a3);
    };

}  // namespace kn

#endif
