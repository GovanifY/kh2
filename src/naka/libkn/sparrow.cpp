#include "types.h"


namespace kn {

} // namespace kn

class DAMAGE;
class Friend;
class FriendAction;
class FriendParam;
class Sparrow;
class TARGET;

class Sparrow {
public:
 Sparrow(Sparrow* a0, Friend* a1, FriendParam* a2);
 ~Sparrow();
 void exec_damage(DAMAGE* a0);
 void deadendclimb(FriendAction* a0, TARGET* a1, void** a2, bool a3);
 void shadowsnipe(FriendAction* a0, TARGET* a1, void** a2, bool a3);
 void bonecrusher(FriendAction* a0, TARGET* a1, void** a2, bool a3);
};
