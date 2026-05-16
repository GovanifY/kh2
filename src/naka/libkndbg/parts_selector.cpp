#include "types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace kn {

} // namespace kn

class MODE;
class OBJ;
class PartsSelector;

class PartsSelector {
public:
 PartsSelector(PartsSelector* a0, OBJ* a1, MODE a2);
 ~PartsSelector();
 void toggle(s32 a0);
 void init(void);
};
