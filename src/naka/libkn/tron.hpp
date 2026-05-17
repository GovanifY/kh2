#ifndef KH2_SRC_NAKA_LIBKN_TRON_HPP
#define KH2_SRC_NAKA_LIBKN_TRON_HPP

#include "../../common/types.h"

class Friend;
class FriendParam;
class Tron;

namespace kn {

    class Tron {
    public:
     Tron(Tron* a0, Friend* a1, FriendParam* a2);
     ~Tron();
    };

}  // namespace kn

#endif
