#ifndef KH2_SRC_HARATA_FREECAMERA_HPP
#define KH2_SRC_HARATA_FREECAMERA_HPP

#include "../common/types.h"

class ObjCamera;

namespace dk {

    class FreeCamera {
    public:
     void update(ObjCamera* a0);
     void create(void);
     void destroy(void);
     void addMenu(void);
    };

}  // namespace dk

#endif
