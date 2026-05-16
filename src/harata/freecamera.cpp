#include "types.h"


class ObjCamera;

namespace dk {

class FreeCamera {
public:
 void update(ObjCamera* a0);
 void create(void);
 void destroy(void);
 void addMenu(void);
};


} // namespace dk
