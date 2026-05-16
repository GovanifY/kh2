#include "types.h"


namespace kn {

} // namespace kn

class Friend;
class FriendAction;
class FriendParam;
class Riku;
class TARGET;

class Riku {
public:
 Riku(Riku* a0, Friend* a1, FriendParam* a2);
 ~Riku();
 void idle(FriendAction* a0, TARGET* a1, void** a2, bool a3);
 void move(FriendAction* a0, TARGET* a1, void** a2, bool a3);
};
