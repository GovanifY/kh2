#pragma once

#include "../../common/types.h"

class Friend;
class FriendAction;
class FriendParam;
class Genie;
class TARGET;

namespace kn {

    class Genie {
    public:
     Genie(Genie* a0, Friend* a1, FriendParam* a2);
     ~Genie();
     void changeForm(s32 a0);
     void exec_initialize(void);
     u64 move(FriendAction* a0, TARGET* a1, void** a2, bool a3);
     u64 potion(FriendAction* a0, TARGET* a1, void** a2, bool a3);
     u16 getLimitCommand(void);
    };

}  // namespace kn

