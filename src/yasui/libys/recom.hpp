#pragma once

#include "../../common/types.h"

namespace YS {

    class RECOM {
    public:
     void init(void);
     void start(COMMAND_SLOT* a0);
     void release(void);
     void exec(void);
    };

}  // namespace YS

