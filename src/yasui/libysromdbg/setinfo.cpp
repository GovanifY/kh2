#include "types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace YS {

} // namespace YS

class COLOR;
class RECT;
class SETINFO;

class SETINFO {
public:
 void draw_func(RECT* a0, COLOR* a1);
 void Init(void);
 void Open(s32 a0);
 ~SETINFO();
};
