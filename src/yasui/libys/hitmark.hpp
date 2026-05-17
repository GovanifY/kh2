#pragma once

#include "../../common/types.h"

class EFFECT;

namespace YS {

    class HITMARK {
    public:
     void Init(void);
     void Exec(void);
     void Add(EFFECT* a0);
    };

}  // namespace YS

