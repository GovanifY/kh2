#include "types.h"


class COLOR;
class LABEL;
class RECT;

namespace YW {

class LABEL {
public:
 LABEL(LABEL* a0, char* a1, s32 a2, s32 a3, s32 a4, s32 a5);
 void draw_func(RECT* a0, COLOR* a1);
 ~LABEL();
};


} // namespace YW
