#include "types.h"


namespace YS {

} // namespace YS

class COLLISION_FLAG {
public:
 void clear(void);
 void enable(s32 a0);
 void disable(s32 a0);
 void reset(s32 a0);
 bool is_enable(s32 a0);
 bool is_disable(s32 a0);
};
