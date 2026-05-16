#include "types.h"


namespace kn {

} // namespace kn

class Friend;
class FriendParam;
class Pin;

class Pin {
public:
 Pin(Pin* a0, Friend* a1, FriendParam* a2);
 ~Pin();
};
