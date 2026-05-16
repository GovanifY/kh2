#include "types.h"


namespace YS {

} // namespace YS

class CODE;
class LIBRETTO;
class PLAYER;
class SYSRC;
class TARGET;
struct TASK;

class SYSRC {
public:
 void CheckThread(TASK* a0);
 void TalkThread(TASK* a0);
 u64 CheckCallback(CODE* a0, LIBRETTO* a1);
 u64 TalkCallback(CODE* a0, LIBRETTO* a1);
 ~SYSRC();
 void check(PLAYER* a0, TARGET* a1);
 void talk(PLAYER* a0, TARGET* a1);
};
