#include "types.h"


namespace dk {

} // namespace dk

struct TASK;

class Pause {
public:
 void disable(s32 a0);
 void enable(s32 a0);
 u64 isDisable(void);
 void init(void);
 void pause_thread(TASK* a0);
};

u32 pause(s32 a0);
