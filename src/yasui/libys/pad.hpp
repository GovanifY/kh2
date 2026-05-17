#pragma once

#include "../../common/types.h"
#include "../../common/task.hpp"


namespace YS {

    class PAD {
    public:
     void make_trigger(u64 a0);
     void clear(u64 a0);
     void ReadTask(TASK* a0);
     void Init(void);
    };

}  // namespace YS

