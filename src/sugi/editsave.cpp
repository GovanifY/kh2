#include "types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace Ts {

} // namespace Ts

class EDITSAVE;

class EDITSAVE {
public:
 EDITSAVE();
 ~EDITSAVE();
 s32 get_gumiship_plan(s32 a0);
 s32 get_tinyship_plan(s32 a0);
 void endian_read(void);
 void endian_write(void);
 s32 Get(void);
};
