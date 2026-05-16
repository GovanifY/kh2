#include "types.h"


namespace dk {

} // namespace dk

class OBJ;

class Turn {
public:
 void start(OBJ* a0, s32 a1, f32 a2, f32 a3);
 u64 exec(void);
};
