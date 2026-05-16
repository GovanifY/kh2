#include "types.h"


namespace dk {

} // namespace dk

class Fade;

class Fade {
public:
 void fadeSetup(u32 a0);
 void update(void);
 void fadeOut(u32 a0, bool a1);
 void fadeIn(u32 a0, bool a1);
 ~Fade();
};
