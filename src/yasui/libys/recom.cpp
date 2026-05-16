#include "types.h"


namespace YS {

} // namespace YS

class COMMAND_SLOT;

class RECOM {
public:
 void init(void);
 void start(COMMAND_SLOT* a0);
 void release(void);
 void exec(void);
};
