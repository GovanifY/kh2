#ifndef KH2_SRC_NAKA_LIBKN_AURON_HPP
#define KH2_SRC_NAKA_LIBKN_AURON_HPP

#include "../../common/types.h"

class Auron;
class Friend;
class FriendAction;
class FriendParam;
class TARGET;

namespace kn {

    class Auron {
    public:
     Auron(Auron* a0, Friend* a1, FriendParam* a2);
     ~Auron();
     void yukizakura(FriendAction* a0, TARGET* a1, void** a2, bool a3);
    };

}  // namespace kn

#endif
