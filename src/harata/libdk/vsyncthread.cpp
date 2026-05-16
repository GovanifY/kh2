#include "types.h"


namespace dk {

} // namespace dk

class FuncDef20;

class VsyncThread {
public:
 void init(void);
 s32 create(char* a0, s32 a1, FuncDef20* a2, void* a3);
 void wait(void);
 void wakeup(void);
 void isleep(void);
 void exec(void* a0);
};
