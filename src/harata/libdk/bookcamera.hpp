#pragma once

#include "../../common/types.h"

class ObjCamera;

namespace dk {

    class BookCamera {
    public:
     void update(ObjCamera* a0);
     void create(void);
    };

}  // namespace dk

