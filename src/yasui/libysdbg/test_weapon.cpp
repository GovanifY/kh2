#include "types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace YS {

} // namespace YS

struct TASK;

class TEST_WEAPON {
public:
 void SelectMenu(s32 a0);
 void ChangeWeaponThread(TASK* a0);
 void Init(void);
};
