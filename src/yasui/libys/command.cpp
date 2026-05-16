#include "types.h"


namespace YS {

} // namespace YS

class COMMAND_ELEM;
class TARGET;

class COMMAND {
public:
 void clear(void);
 void set(s32 a0, TARGET* a1, COMMAND_ELEM* a2);
};
