#include "types.h"


namespace dk {

} // namespace dk

class ObjCamera;
struct TASK;

class TalkCamera {
public:
 void calcCamera(ObjCamera* a0);
 void update(ObjCamera* a0);
 void ensureTask(TASK* a0);
};
