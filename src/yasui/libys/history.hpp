#pragma once

#include "../../common/types.h"

namespace YS {

    class HISTORY {
    public:
     void init(void);
     void next(s32 a0);
     void set(s32 a0);
     void unset(s32 a0);
     u64 is_set(s32 a0);
     void clear(void);
     void Clear(void);
     void Init(void);
    };

}  // namespace YS

