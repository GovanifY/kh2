#pragma once

#include "../../common/types.h"

namespace YS {

    class JIGSAW {
    public:
     void Get(s32 a0, s32 a1);
     void get(void);
     bool is_get(void);
     u64 can_get(void);
     void Init(void);
     s32 GetTable(s32 a0, s32 a1, s32 a2);
    };

}  // namespace YS

