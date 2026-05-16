#include "types.h"


namespace kn {

} // namespace kn

class Beast;
class Friend;
class FriendAction;
class FriendParam;
class TARGET;

class Beast {
public:
 Beast(Beast* a0, Friend* a1, FriendParam* a2);
 ~Beast();
 void shout(FriendAction* a0, TARGET* a1, void** a2, bool a3);
 void ferociouslunge(FriendAction* a0, TARGET* a1, void** a2, bool a3);
};
