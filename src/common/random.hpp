#pragma once

#include "./types.h"

namespace SQEX {

class Random {
public:
 u32 GetInt(void);
 double GetFloat(void);
 s16 GetRangeShort(s16 a0, s16 a1);
};

} // namespace SQEX

