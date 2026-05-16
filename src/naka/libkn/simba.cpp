#include "types.h"


namespace kn {

} // namespace kn

class Friend;
class FriendAction;
class FriendParam;
class Simba;
class TARGET;

class Simba {
public:
 Simba(Simba* a0, Friend* a1, FriendParam* a2);
 ~Simba();
 void bloodyclaw(FriendAction* a0, TARGET* a1, void** a2, bool a3);
 void earthshaker(FriendAction* a0, TARGET* a1, void** a2, bool a3);
};
