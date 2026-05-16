#include "types.h"


namespace YS {

} // namespace YS

class OBJ;

class SINGLETON_EFFECT {
public:
 void start_bind(s32 a0, OBJ* a1);
 void kill(void);
 void loop_end_kill(void);
 void exec(void);
 void loop_end(void);
};
