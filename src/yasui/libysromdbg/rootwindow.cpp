#include "types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace YS {

} // namespace YS

class COLOR;
class EVENT;
class RECT;
class ROOTWINDOW;

class ROOTWINDOW {
public:
 void focus_func(EVENT a0, s32 a1, s32 a2);
 void draw_func(RECT* a0, COLOR* a1);
 ~ROOTWINDOW();
};
