#include "types.h"


namespace dk {

} // namespace dk

class ObjCamera;
class PAD;

class DangleCamera {
public:
 void calcEyeTarget(ObjCamera* a0);
 void control(PAD* a0, ObjCamera* a1);
 void update(ObjCamera* a0);
 s32 create(void);
 s32 destroy(void);
};
