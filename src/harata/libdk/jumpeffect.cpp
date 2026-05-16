#include "types.h"


namespace dk {

} // namespace dk

struct TASK;

class JumpEffect {
public:
 void outInit(void);
 void inInit(void);
 void outFinal(void);
 void inFinal(void);
 void outInit_task(TASK* a0);
 s32 in(void);
 u8 outIsExist(void);
 void init(void);
 void outClear(void);
};
