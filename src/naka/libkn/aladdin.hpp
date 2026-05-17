#ifndef KH2_SRC_NAKA_LIBKN_ALADDIN_HPP
#define KH2_SRC_NAKA_LIBKN_ALADDIN_HPP

#include "../../common/types.h"

class Aladdin;
class Friend;
class FriendAction;
class FriendParam;
class TARGET;

namespace kn {

    class Aladdin {
    public:
     Aladdin(Aladdin* a0, Friend* a1, FriendParam* a2);
     ~Aladdin();
     void slashrush(FriendAction* a0, TARGET* a1, void** a2, bool a3);
     void quickplay(FriendAction* a0, TARGET* a1, void** a2, bool a3);
    };

}  // namespace kn

#endif
