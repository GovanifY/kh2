#include "types.h"


namespace dk {

} // namespace dk

struct TASK;

class Error {
public:
 void disable(void);
 void enable(void);
 void init(void);
 void error_task(TASK* a0);
};
