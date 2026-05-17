#pragma once

#include "../common/types.h"

namespace Tz {

class Mg2DTron {
public:
    Mg2DTron();
    void Leave(s32);
    ~Mg2DTron();
    void CreateSeq(s32, s32);
};

}  // namespace Tz

