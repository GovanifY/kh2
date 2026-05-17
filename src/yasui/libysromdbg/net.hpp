#pragma once

#include "../../common/types.h"

class ACCEPT_TABLE;

namespace YS {

    class NET {
    public:
     void AddAcceptCallback(ACCEPT_TABLE* a0);
     void Lock(void);
     void Unlock(void);
    };

}  // namespace YS

