#pragma once

#include "../common/types.h"

class ALLOCATOR;

namespace Tz {

class Crc {
public:
    void MakeTable();
    void CalcInit();
    void Init(ALLOCATOR*);
    void End();
    u32 Calc(uchar*, s32);
};

}  // namespace Tz

