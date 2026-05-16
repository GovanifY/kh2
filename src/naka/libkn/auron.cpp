#include "types.h"


namespace kn {

} // namespace kn

class Auron;
class Friend;
class FriendAction;
class FriendParam;
class TARGET;

class Auron {
public:
 Auron(Auron* a0, Friend* a1, FriendParam* a2);
 ~Auron();
 void yukizakura(FriendAction* a0, TARGET* a1, void** a2, bool a3);
};
