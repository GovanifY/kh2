#include "types.h"


namespace dk {

} // namespace dk

class Frame;

class Frame {
public:
 Frame();
 void setFrame(u16 a0, u32 a1, u16 a2, u16 a3);
 s32 widthToTW(u32 a0);
};
