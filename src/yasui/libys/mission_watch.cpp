#include "types.h"


namespace YS {

} // namespace YS

class MISSION_WATCH;

class MISSION_WATCH {
public:
 void init(s32 a0);
 void set_param(s32 a0, s32 a1, s32 a2);
 void activate(void);
 void deactivate(void);
 ~MISSION_WATCH();
};
