#pragma once

#include "../../common/types.h"

namespace YS {

class EFFECT {
public:
 void Read(void);
 void Init(void);
 void Ensure(void);
 void Exec(void);
 void AddDeadEffect(EFFECT* a0);
};

} // namespace YS

