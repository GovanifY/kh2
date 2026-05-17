#pragma once

#include "../../common/types.h"
#include "../../common/task.hpp"

class ITEM_EFFECT;
class OBJ;

namespace YS {

    class ITEM_EFFECT {
    public:
     void use(void);
     u64 exec(void);
     ~ITEM_EFFECT();
     void Exec(TASK* a0);
     void Init(void);
     void ClearAll(void);
     void Cast(OBJ* a0);
    };

}  // namespace YS

