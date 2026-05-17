#ifndef KH2_SRC_NAKA_LIBKN_SIMBA_HPP
#define KH2_SRC_NAKA_LIBKN_SIMBA_HPP

#include "../../common/types.h"

class Friend;
class FriendAction;
class FriendParam;
class Simba;
class TARGET;

namespace kn {

    class Simba {
    public:
     Simba(Simba* a0, Friend* a1, FriendParam* a2);
     ~Simba();
     void bloodyclaw(FriendAction* a0, TARGET* a1, void** a2, bool a3);
     void earthshaker(FriendAction* a0, TARGET* a1, void** a2, bool a3);
    };

}  // namespace kn

#endif
