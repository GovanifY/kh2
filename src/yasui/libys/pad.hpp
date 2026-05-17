#pragma once

#include "../../common/types.h"

struct TASK;

namespace YS {

    class PAD {
    public:
     void make_trigger(u64 a0);
     void clear(u64 a0);
     void ReadTask(TASK* a0);
     void Init(void);
    };

}  // namespace YS

