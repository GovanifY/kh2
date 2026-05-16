#include "types.h"


namespace YS {

} // namespace YS

class PAD;
struct TASK;
class TRPLAYER;
class ZONE;

class LIGHTCYCLE {
public:
 void check_turn(TRPLAYER* a0, PAD* a1);
 void exec(void);
 void Exec(TASK* a0);
 void Ensure(TASK* a0);
 void Init(void);
 void Set(ZONE* a0, s32 a1, bool a2);
};
