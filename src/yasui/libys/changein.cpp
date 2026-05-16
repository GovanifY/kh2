#include "types.h"


namespace YS {

} // namespace YS

class CHANGEIN;
class FRIEND;
class OBJ;
struct TASK;

class CHANGEIN {
public:
 void exec(TASK* a0);
 CHANGEIN(CHANGEIN* a0, s32 a1, FRIEND* a2, s32 a3);
 void Thread(TASK* a0);
 void ThreadFinalizer(TASK* a0);
 void Start(OBJ* a0);
 void Stop(void);
 u64 CanExec(void);
};
