#include "types.h"


namespace kn {

} // namespace kn

class Friend;
class FriendAction;
class FriendParam;
class Peterpan;
class TARGET;

class Peterpan {
public:
 Peterpan(Peterpan* a0, Friend* a1, FriendParam* a2);
 ~Peterpan();
 u64 execScriptAttack(FriendAction* a0, TARGET* a1, void** a2, bool a3);
 void startWarpEffect(void);
 u64 receiveNotifyPlayerTarget(void);
 void acceptNotifyPlayerTarget(void);
};
