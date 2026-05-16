#include "types.h"


class DESKTOP;

namespace YW {

class DESKTOP {
public:
 DESKTOP(DESKTOP* a0, s32 a1, s32 a2, s32 a3, s32 a4, u32 a5);
 void send_font(void);
 void exec(f32 a0, f32 a1, u32 a2);
 ~DESKTOP();
};


} // namespace YW
