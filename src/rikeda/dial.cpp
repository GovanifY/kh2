#include "types.h"


class COLOR;
class DIAL;
class EVENT;
class FuncDef78;
class RECT;

namespace ryj {

class DIAL {
public:
 void set_number(s32 a0);
 DIAL(DIAL* a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, FuncDef78* a7);
 s32 get_number(void);
 void focus_func(EVENT a0, s32 a1, s32 a2);
 void draw_func(RECT* a0, COLOR* a1);
 ~DIAL();
};


} // namespace ryj
