#pragma once

#include "../common/types.h"

namespace Tz {

class MenuPad {
public:
    void Push(s32 a0);
    void PushEnable(void);
    void Pop(void);
    void Reset(void);
};

}  // namespace Tz

