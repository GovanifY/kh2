#include "types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace YS {

} // namespace YS

class COLOR;
class EVENT;
class RECT;
class TEST_MISSION;
class WINDOW;

class TEST_MISSION {
public:
 TEST_MISSION(TEST_MISSION* a0, WINDOW* a1, s32 a2);
 void idle_func(void);
 void draw_func(RECT* a0, COLOR* a1);
 void focus_func(EVENT a0, s32 a1, s32 a2);
 void Open(s32 a0);
 void Init(void);
 ~TEST_MISSION();
};
