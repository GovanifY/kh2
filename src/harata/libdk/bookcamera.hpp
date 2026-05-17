#ifndef KH2_SRC_HARATA_LIBDK_BOOKCAMERA_HPP
#define KH2_SRC_HARATA_LIBDK_BOOKCAMERA_HPP

#include "../../common/types.h"

class ObjCamera;

namespace dk {

    class BookCamera {
    public:
     void update(ObjCamera* a0);
     void create(void);
    };

}  // namespace dk

#endif
