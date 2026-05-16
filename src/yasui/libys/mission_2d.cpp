#include "types.h"


namespace YS {

} // namespace YS

class ALIGN;
class MISSION2D;

class MISSION2D {
public:
 void init(s32 a0);
 void activate(void);
 void deactivate(void);
 void set_warning(void);
 void set_param(s32 a0, s32 a1, s32 a2);
 void check_warning(s32 a0);
 void set_image(ALIGN a0, s32 a1);
 void disable(void);
 ~MISSION2D();
 void reset_warning(void);
};
