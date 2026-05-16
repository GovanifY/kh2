#include "types.h"


namespace kn {

} // namespace kn

class Aladdin;
class Friend;
class FriendAction;
class FriendParam;
class TARGET;

class Aladdin {
public:
 Aladdin(Aladdin* a0, Friend* a1, FriendParam* a2);
 ~Aladdin();
 void slashrush(FriendAction* a0, TARGET* a1, void** a2, bool a3);
 void quickplay(FriendAction* a0, TARGET* a1, void** a2, bool a3);
};
