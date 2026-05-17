#pragma once

#include "../../common/types.h"

namespace YS {

class TEST_STOP {
public:
    void Init(void);
    void StartCallback(s32 a0);
    void EndCallback(s32 a0);
};

}  // namespace YS

