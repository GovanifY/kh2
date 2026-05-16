#include "types.h"


namespace Tz {

} // namespace Tz

class COLOR;
class DbgPuzzle;
class EVENT;
class RECT;

class DbgPuzzle {
public:
 DbgPuzzle();
 ~DbgPuzzle();
 void idle_func(void);
 void focus_func(EVENT a0, s32 a1, s32 a2);
 void draw_func(RECT* a0, COLOR* a1);
 void Open(s32 a0);
 void GetAll(void* a0);
 void Init(void);
};
