#include "types.h"


namespace kn {

} // namespace kn

class Friend;
class FriendAction;
class FriendParam;
class Mulan;
class TARGET;

class Mulan {
public:
 Mulan(Mulan* a0, Friend* a1, FriendParam* a2);
 ~Mulan();
 void mushufire(FriendAction* a0, TARGET* a1, void** a2, bool a3);
 void flametongue(FriendAction* a0, TARGET* a1, void** a2, bool a3);
};
