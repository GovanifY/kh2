#include "types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace YS {

} // namespace YS

class WIDGET;

class TEST_ACTION {
public:
 void ActionIdle(s32 a0);
 void ActionFly(s32 a0);
 void ActionHover(s32 a0);
 void ActionHop(s32 a0);
 void ActionCarpet(s32 a0);
 void ActionLightCycle(s32 a0);
 void CarpetWindowFinalizer(WIDGET* a0);
 void Init(void);
};
