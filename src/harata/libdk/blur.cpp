#include "types.h"


namespace dk {

} // namespace dk

struct TASK;
class uchar;

class Blur {
public:
 void update(void);
 void init(void);
 void blur_task(TASK* a0);
 void setBlurAlpha(uchar a0);
 void setBlurXYSize(u16 a0, u16 a1);
 void setBlurRot(f32 a0, s32 a1);
 void setBlurFlag(bool a0);
 void setBlurType(bool a0);
};
