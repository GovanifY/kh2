#ifndef KH2_SRC_NAKA_LIBKN_TINK_HPP
#define KH2_SRC_NAKA_LIBKN_TINK_HPP

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

#endif
