#include "types.h"


namespace kn {

} // namespace kn

class Friend;
class FriendAction;
class FriendParam;
class Goofy;
class TARGET;

class Goofy {
public:
 Goofy(Goofy* a0, Friend* a1, FriendParam* a2);
 ~Goofy();
 u64 rush(FriendAction* a0, TARGET* a1, void** a2, bool a3);
 void blade(FriendAction* a0, TARGET* a1, void** a2, bool a3);
};
