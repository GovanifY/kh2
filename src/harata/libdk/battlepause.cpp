#include "types.h"


namespace dk {

} // namespace dk

struct TASK;

class BattlePause {
public:
 void init(void);
 void pause_thread(TASK* a0);
};
